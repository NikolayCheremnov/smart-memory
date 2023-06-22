#include "boostmemorygraph.h"

using namespace memory;

BoostMemoryGraph::BoostMemoryGraph()
{

}

BoostMemoryGraph::VertexDescriptor BoostMemoryGraph::add_node(int_fast32_t weight)
{
    VertexDescriptor node =
            boost::add_vertex(Node{generator(), weight}, graph);
    return node;
}

BoostMemoryGraph::EdgeDescriptor BoostMemoryGraph::add_edge(int_fast32_t weight,
                                BoostMemoryGraph::VertexDescriptor from,
                                BoostMemoryGraph::VertexDescriptor to)
{
    EdgeDescriptor edge = boost::add_edge(from, to, Edge{generator(), weight}, graph).first;
    return edge;
}
