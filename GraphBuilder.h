#ifndef GRAPHBUILDER_H
#define GRAPHBUILDER_H
#include "GraphAdjList.h"
#include "GraphEdgeList.h"
class GraphBuilder{
public:
    GraphAdjList buildGraphAdjList();
    GraphEdgeList buildGraphEdgeList();
    GraphEdgeList buildDirectedMultiGraphEdgeList();
};
#endif // GRAPHBUILDER_H
