#ifndef GRAPHBUILDER_H
#define GRAPHBUILDER_H
#include "GraphAdjList.h"
#include "GraphEdgeList.h"
using namespace std;

class GraphBuilder
{
public:
    GraphAdjList buildGraphAdjList(istream& in, ostream& out);
    GraphEdgeList buildGraphEdgeList(istream& in, ostream& out);
    GraphEdgeList buildDirectedMultiGraphEdgeList(istream& in, ostream& out);
};
#endif // GRAPHBUILDER_H
