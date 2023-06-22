#define BOOST_TEST_MODULE BoostMemoryGraphTest
#include <boost/test/included/unit_test.hpp>
#include "../memory/graph/boostmemorygraph.h"

BOOST_AUTO_TEST_CASE(test_create_boost_graph)
{
    memory::BoostMemoryGraph graph;
    auto node_1 = graph.add_node(1);
    auto node_2 = graph.add_node(2);
    auto edge = graph.add_edge(3, node_1, node_2);
}
