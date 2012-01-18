/******************************************************************************
 *
 *	PlanoCarreira.h
 *
 *      Encapsulates a CareerGraph and provides operations to
 *      access it.
 *
 *	Created at:
 *	2012-01-17
 *
 *	Author(s):
 *
 *		B5-8 LAPRIII group
 *
 *****************************************************************************/

#ifndef _PLANOCARREIRA_H
#define _PLANOCARREIRA_H

#include <iostream>
#include <string>

#include <boost/graph/adjacency_list.hpp>

namespace dmd
{

typedef boost::adjacency_list <> CareerGraph;
typedef boost::graph_traits< boost::adjacency_list <> >::vertex_iterator VertexIterator;
typedef boost::graph_traits< boost::adjacency_list <> >::adjacency_iterator AdjacencyIterator;

class PlanoCarreira
{
private:
    CareerGraph *careerGraph;
    std::string description;

public:
    PlanoCarreira(const std::string &desc="") :
            description(desc) { careerGraph = new boost::adjacency_list<> (); }

    ~PlanoCarreira();

    CareerGraph* getCareerGraph() const { return careerGraph; }

    void write(std::ostream &outStream);
};

}

#endif /* _PLANOCARREIRA_H */
