#ifndef BOOSTMEMORYGRAPH_H
#define BOOSTMEMORYGRAPH_H

#include "memorygraph.h"

#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graph_traits.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>

namespace memory {

    class BoostMemoryGraph : public MemoryGraph
    {
    public:
        // node and edge data structs definitions
        struct Node {
            boost::uuids::uuid UUID;
            int_fast32_t weight;
        };

        struct Edge {
            boost::uuids::uuid UUID;
            int_fast32_t weight;
        };

    private:
        // boost graph datatypes typedefs
        typedef boost::adjacency_list<
            boost::vecS, boost::vecS,
            boost::directedS,
            Node, Edge,
            boost::property<boost::edge_weight_t, int_fast32_t>
        > Graph;
        typedef boost::graph_traits<BoostMemoryGraph::Graph>::vertex_descriptor VertexDescriptor;
        typedef boost::graph_traits<Graph>::edge_descriptor EdgeDescriptor;

    private:
        Graph graph;
        boost::uuids::random_generator generator;
    public:
        BoostMemoryGraph();

        // temporary test methods working with graph
        VertexDescriptor add_node(int_fast32_t weight);
        EdgeDescriptor add_edge(int_fast32_t weight, VertexDescriptor from, VertexDescriptor to);
    };
}

#endif // BOOSTMEMORYGRAPH_H
