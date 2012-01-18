#include "PlanoCarreira.h"

#include <iostream>
#include <string>
#include <utility>

#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/depth_first_search.hpp>
#include <boost/graph/visitors.hpp>

using std::string;
using std::cout;
using std::endl;
using std::ostream;
using std::pair;

using dmd::PlanoCarreira;
using dmd::CareerGraph;
using dmd::VertexIterator;
using dmd::AdjacencyIterator;

using boost::dfs_visitor;
using boost::depth_first_search;

PlanoCarreira::~PlanoCarreira()
{
    delete careerGraph;
}

void PlanoCarreira::write(ostream &outStream)
{
    struct DFSCallback : public dfs_visitor<>
    {
        template <class Vertex, class Graph>
        void discover_vertex(Vertex v, Graph&)
        {
            outStream << v.getDescription() << endl;
        }
    } callback;

    depth_first_search(careerGraph, callback);
}
