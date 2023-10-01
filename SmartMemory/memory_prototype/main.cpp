#include <QCoreApplication>

#include <iostream>

#include <model/datatypes.h>

#include <factory/model/memoryregionfactory.h>

#include <graph_utils/dotgenerator.h>
#include <graph_utils/graphvizimagegenerator.h>

#include <algorithms/initializer/randommemoryregioninitializer.h>
#include <algorithms/column/percentagecolumnactivationstrategy.h>
#include <algorithms/synapse/simplethresholdsynapseactivationstrategy.h>
#include <algorithms/input/input.h>
#include <algorithms/input/bytearrsignal.h>
#include <algorithms/sensor/sensor.h>
#include <algorithms/sensor/charsensor.h>
#include <algorithms/sensor/mappulsedispatcher.h>
#include <algorithms/overlap/minoverlappingstrategy.h>
#include <algorithms/inhibition/localthresholdinhibitionstrategy.h>
#include <algorithms/learning/standardlearningstrategy.h>
#include <algorithms/spatial/localradiusspatialviewstrategy.h>
#include <algorithms/cell/sufficientcellactivationstrategy.h>
#include <algorithms/temporal/temporal.h>
#include <algorithms/temporal/linearlateralbooster.h>
#include <algorithms/temporal/temporalstatesrecognitionstrategy.h>
#include <algorithms/temporal/enoughstatelearningstrategy.h>
#include <algorithms/segment/segment.h>
#include <algorithms/segment/percentagesegmentactivationstrategy.h>

//void create_and_print_empty_memory();
//void create_and_print_preinitialized_memory();
//void process_signal_by_sensor();
void memory_initialization();

// INTERGATION TEST FUNCTIONS
void process_signal_with_memory();

// HELP PRINT FUNCTIONS
void print_memory_debug(model::MemoryRegionPtr region, std::string fname);
void print_dispatched_pulses(model::MemoryRegionPtr region, algorithms::IPulseDispatcherPtr dispatcher);
void print_overlapping_map(std::map<std::string, double>& overlap, std::string title);
void print_column_activation_map(std::map<std::string, bool>& column_activation_map, std::string title);

int main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);

    // call tset procedures
    // create_and_print_empty_memory();
    // create_and_print_preinitialized_memory();
    // process_signal_by_sensor();
    // memory_initialization();
    process_signal_with_memory();

    //return a.exec();
}

void process_signal_with_memory() {
    // 1. create empty region
    size_t column_count = 8, column_height = 6;
    model::MemoryRegionPtr region = factory::MemoryRegionFactory::make(column_count, column_height);
    // 2. create strategies
    algorithms::ISynapseActivationStrategy* synapse_activation_strategy = new algorithms::SimpleThresholdSynapseActivationStrategy(0.9);
    algorithms::ISpatialViewSrategy* spatial_view_strategy = new algorithms::LocalRadiusSpatialViewStrategy();
    algorithms::IColumnActivationStrategy* column_activation_strategy = new algorithms::PercentageColumnActivationStrategy(90.0);
    algorithms::IRecognitionStrategy* recognition_strategy = new algorithms::TemporalStatesRecognitionStrategy();
    algorithms::ICellSideFeedActivationStrategy* cell_side_feed_activation_strategy = new algorithms::SufficientCellActivationStrategy(90.0);
    algorithms::IOverlappingStrategy* overlapping_strategy = new algorithms::MinOverlappingStrategy(1);
    algorithms::IInhibitionaStrategy* inhibition_strategy = new algorithms::LocalThresholdInhibitionStrategy(1);
    algorithms::ISegmentActivationStrategyPtr segment_activation_strategy = algorithms::ISegmentActivationStrategyPtr(new algorithms::PercentageSegmentActivationStrategy(90.0));
    algorithms::ILearningStrategy* learning_strategy = new algorithms::StandardLearningStrategy(0.1, 0.1, 1.0, 0.0, 0.01, 1.1, 1.1);
    algorithms::ILateralCatalystPtr lateral_catalyst = algorithms::ILateralCatalystPtr(new algorithms::LinearLateralBooster(0.1, segment_activation_strategy));
    algorithms::ILateralInhibitorPtr lateral_inhibitor = algorithms::ILateralInhibitorPtr(new algorithms::LinearLateralBooster(0.1, segment_activation_strategy));
    algorithms::ITemporalLearningStrategy* temporal_learning_strategy = new algorithms::EnoughStateLearningStrategy(lateral_catalyst, lateral_inhibitor);
    // 3. initialize memory
    algorithms::RandomMemoryRegionInitializer::SynapsesInitializerArgs args;
    args.min_proximal_synapses = 1;
    args.max_proximal_synapses = 1;
    args.min_proximal_permanent = 0.1;
    args.max_proximal_permanent = 1.5;
    args.min_distal_synapses = 1;
    args.max_distal_synapses = 3;
    args.min_distal_permanent = 0.1;
    args.max_distal_permanent = 1.5;
    size_t distal_radius = 1;
    algorithms::RandomMemoryRegionInitializer initializer;
    initializer.initialize_memory_region(
                region, args, distal_radius,
                synapse_activation_strategy,
                spatial_view_strategy,
                column_activation_strategy,
                recognition_strategy,
                cell_side_feed_activation_strategy
    );
    print_memory_debug(region, "empty");
    // 4. prepare signal and sensor and read signal to dispatcher
    const int N = 1;
    char source_data[N]{'a'};
    algorithms::InputSignalBasePtr signal(new algorithms::ByteArrSignal(source_data, N));
    algorithms::ISensor* sensor = new algorithms::CharSensor();
    algorithms::IPulseDispatcherPtr dispatcher = sensor->read_signal(signal, region);
    print_dispatched_pulses(region, dispatcher);
    // 5. START SIGNAL PROCESSING
    // 5.1. calculate overlapping
    std::map<std::string, double> overlap = overlapping_strategy->calculate_overlapping(region, dispatcher, synapse_activation_strategy);
    print_overlapping_map(overlap, "empty memory and single signal");
    // 5.2. make inhibition
    std::map<std::string, bool> column_activation_map = inhibition_strategy->process_column_inhibition(region, overlap);
    print_column_activation_map(column_activation_map, "empty memory and single signal");
    // 5.3. make learning
    learning_strategy->make_learning(region, column_activation_map);
    print_memory_debug(region, "after_learning");
    // 5.4. temporal recognition
    recognition_strategy->make_recognition(region, cell_side_feed_activation_strategy, column_activation_map);
    print_memory_debug(region, "after_recognition");
    // 5.5. temporal learning
    temporal_learning_strategy->temporal_learning(region);
    print_memory_debug(region, "after_tempral_learning");
    // at last clear memory
    delete synapse_activation_strategy;
    delete spatial_view_strategy;
    delete column_activation_strategy;
    delete recognition_strategy;
    delete cell_side_feed_activation_strategy;
    delete overlapping_strategy;
    delete inhibition_strategy;
    delete temporal_learning_strategy;
    delete sensor;
}

void memory_initialization() {
    // 1. create empty memory region
    size_t column_count = 8, column_height = 6;
    model::MemoryRegionPtr region = factory::MemoryRegionFactory::make(column_count, column_height);
    // 2. create synapses initializer args
    algorithms::RandomMemoryRegionInitializer::SynapsesInitializerArgs args;
    args.min_proximal_synapses = 1;
    args.max_proximal_synapses = 8;
    args.min_proximal_permanent = 0.0;
    args.max_proximal_permanent = 1.5;
    args.min_distal_synapses = 1;
    args.max_distal_synapses = 3;
    args.min_distal_permanent = 0.0;
    args.max_distal_permanent = 1.5;
    // 3. create strategies and intiializer
    algorithms::ISynapseActivationStrategy* synapse_activation_strategy = new algorithms::SimpleThresholdSynapseActivationStrategy(0.9);
    algorithms::ISpatialViewSrategy* spatial_view_strategy = new algorithms::LocalRadiusSpatialViewStrategy();
    algorithms::IColumnActivationStrategy* column_activation_strategy = new algorithms::PercentageColumnActivationStrategy(50.0);
    algorithms::ICellSideFeedActivationStrategy* cell_side_feed_activation_strategy = new algorithms::SufficientCellActivationStrategy(50.0);
    algorithms::IRecognitionStrategy* recognition_strategy = new algorithms::TemporalStatesRecognitionStrategy();
    algorithms::RandomMemoryRegionInitializer initializer;
    // 4. first initialize memory
    size_t distal_radius = 1;
    initializer.initialize_memory_region(
        region,
        args,
        distal_radius,
        synapse_activation_strategy,
        spatial_view_strategy,
        column_activation_strategy,
        recognition_strategy,
        cell_side_feed_activation_strategy
    );
    // 5. print memory
    print_memory_debug(region, "initialized");
    // delete strategies
    delete synapse_activation_strategy;
    delete spatial_view_strategy;
    delete column_activation_strategy;
    delete cell_side_feed_activation_strategy;
    delete recognition_strategy;
}

/***
 *
 * HELP PRINT FUNCTIONS
 *
 ***/

void print_memory_debug(model::MemoryRegionPtr region, std::string fname) {
    gu::DotGenerator dot_generator;
    std::string dot_columns = dot_generator.generate_cellular_memory_frame_as_dot(region);
    std::string dot_full = dot_generator.generate_total_memory_frame_as_dot(region);
    std::cout << fname + " columns dot: " << std::endl;
    std::cout << dot_columns << std::endl;
    std::cout << dot_full << std::endl;
    // 6. write memory to graph
    std::string dot_path = "D:\\DevKit\\Graphviz\\bin\\dot.exe";
    std::string tmp_path = ".";
    std::string result_path = ".\\" + fname + "_columns.png";
    gu::GraphVizImageGenerator image_generator(dot_path, tmp_path);
    image_generator.process_dot(dot_columns, result_path);
    result_path = ".\\" + fname + "_full.png";
    image_generator.process_dot(dot_full, result_path);
}

void print_dispatched_pulses(model::MemoryRegionPtr region, algorithms::IPulseDispatcherPtr dispatcher) {
    std::cout << "dispatched signals:\n";
   for (size_t i = 0; i < region->get_cortical_columns_set_size(); i++) {
       auto column = region->get_cortical_column_by_index(i);
       auto proximal_segment = column->get_proximal_dendritic_segment();
       size_t proximal_synapses_count = proximal_segment->get_segment_size();
       for (size_t j = 0; j < proximal_synapses_count; j++) {
           auto synapse = column->get_proximal_dendritic_segment()->get_segment_synapse_by_index(j);
           bool signal = dispatcher->read_synapse_pulse(synapse);
           std::cout << synapse->short_uuid_str() << ": " << signal << std::endl;
       }
   }
}

void print_overlapping_map(std::map<std::string, double>& overlap, std::string title) {
    std::cout << title << " overlap:\n";
    for (std::pair<std::string, double> item : overlap) {
        std::cout << item.first << ": " << item.second << std::endl;
    }
}

void print_column_activation_map(std::map<std::string, bool>& column_activation_map, std::string title) {
    std::cout << title << " column activation map:\n";
    for (std::pair<std::string, double> item : column_activation_map) {
        std::cout << item.first << ": " << item.second << std::endl;
    }
}


//void create_and_print_preinitialized_memory() {
//    // 1. create empty memory region for char sensor
//    size_t column_count = 8, column_height = 6;
//    model::MemoryRegionPtr region = factory::MemoryRegionFactory::make(column_count, column_height);
//    // 2. create initializer args
//    algorithms::RandomMemoryRegionInitializer::RandomMemoryRegionInitializerArgs args;
//    args.min_synapses = 1;
//    args.max_synapses = 1;
//    args.min_permanent = 0.0;
//    args.max_permanent = 0.0;
//    // 3. create strategies and intiializer
//    algorithms::IColumnActivationStrategy* column_activation_strategy = new algorithms::PercentageColumnActivationStrategy(90.0);
//    algorithms::ISynapseActivationStrategy* synapse_activation_strategy = new algorithms::SimpleThresholdSynapseActivationStrategy(0.9);
//    algorithms::RandomMemoryRegionInitializer initializer;
//    // 4. initialize memory
//    initializer.initialize_memory_region(region, args, synapse_activation_strategy, column_activation_strategy);
//    // 5. print memory
//    gu::DotGenerator dot_generator;
//    std::string dot = dot_generator.generate_cellular_memory_frame_as_dot(region);
//    std::cout << dot << std::endl;
//    // 6. write memory to graph
//    std::string dot_path = "D:\\DevKit\\Graphviz\\bin\\dot.exe";
//    std::string tmp_path = ".";
//    std::string result_path = ".\\result.png";
//    gu::GraphVizImageGenerator image_generator(dot_path, tmp_path);
//    image_generator.process_dot(dot, result_path);
//    // at last release memory
//    delete column_activation_strategy;
//    delete synapse_activation_strategy;
//}

//void process_signal_by_sensor() {
//    // 1. create empty region
//    size_t column_count = 8, column_height = 6;
//    model::MemoryRegionPtr region = factory::MemoryRegionFactory::make(column_count, column_height);
//    // 2. create initializer args
//    algorithms::RandomMemoryRegionInitializer::RandomMemoryRegionInitializerArgs args;
//    args.min_synapses = 1;
//    args.max_synapses = 1;
//    args.min_permanent = 0.0;
//    args.max_permanent = 0.0;
//    // 3. create strategies and intiializer
//    algorithms::IColumnActivationStrategy* column_activation_strategy = new algorithms::PercentageColumnActivationStrategy(90.0);
//    algorithms::ISynapseActivationStrategy* synapse_activation_strategy = new algorithms::SimpleThresholdSynapseActivationStrategy(0.9);
//    algorithms::RandomMemoryRegionInitializer initializer;
//    // 4. initialize memory
//    initializer.initialize_memory_region(region, args, synapse_activation_strategy, column_activation_strategy);
//    // 6. prepare signal and sensors objects
//    char source_data[1]{'a'};
//    algorithms::InputSignalBasePtr signal(new algorithms::ByteArrSignal(source_data, 1));
//    algorithms::ISensor* sensor = new algorithms::CharSensor();
//    // 7. read and print signal
//    algorithms::IPulseDispatcherPtr dispatcher = sensor->read_signal(signal, region);
//    std::cout << "dispatched signals:\n";
//    for (size_t i = 0; i < region->get_cortical_columns_set_size(); i++) {
//        auto column = region->get_cortical_column_by_index(i);
//        auto synapse = column->get_proximal_dendritic_segment()->get_segment_synapse_by_index(0);
//        bool signal = dispatcher->read_synapse_pulse(synapse);
//        std::cout << synapse->short_uuid_str() << ": " << signal << std::endl;
//    }
//    // 8. calculate overlapping
//    algorithms::IOverlappingStrategy* overlapping_strategy = new algorithms::MinOverlappingStrategy(1);
//    std::map<std::string, double> overlap = overlapping_strategy->calculate_overlapping(region, dispatcher);
//    std::cout << "overlap:\n";
//    for (std::pair<std::string, double> item : overlap) {
//        std::cout << item.first << ": " << item.second << std::endl;
//    }
//    // 9. make inhibition
//    algorithms::LocalThresholdInhibitionStrategy* inhibition_strategy = new algorithms::LocalThresholdInhibitionStrategy(1);
//    inhibition_strategy->process_column_inhibition(region, overlap);
//    // 10. make learning
//    algorithms::ILearningStrategy* learning_strategy = new algorithms::StandardLearningStrategy(0.1, 0.1, 1.0, 0.0);
//    learning_strategy->make_learning(region);
//    // 8. print memory
//    gu::DotGenerator dot_generator;
//    std::string dot = dot_generator.generate_cellular_memory_frame_as_dot(region);
//    std::cout << dot << std::endl;
//    // 9. write memory to graph
//    std::string dot_path = "D:\\DevKit\\Graphviz\\bin\\dot.exe";
//    std::string tmp_path = ".";
//    std::string result_path = std::string(".\\result_") + 'a' + ".png";
//    gu::GraphVizImageGenerator image_generator(dot_path, tmp_path);
//    image_generator.process_dot(dot, result_path);
//    // at last release memory
//    // delete column_activation_strategy;
//    // delete synapse_activation_strategy;
//    delete sensor;
//    delete overlapping_strategy;
//    delete inhibition_strategy;
//    delete learning_strategy;
//}

//void create_and_print_empty_memory() {
//    size_t column_count = 10, column_height = 6;
//    model::MemoryRegionPtr region = factory::MemoryRegionFactory::make(column_count, column_height);
//    gu::DotGenerator dot_generator;
//    std::string dot = dot_generator.generate_cellular_memory_frame_as_dot(region);
//    std::cout << dot << std::endl;
//}
