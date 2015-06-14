#ifndef GRAPHCONVERTER_H
#define GRAPHCONVERTER_H
#include "GraphAdjList.h"
#include "GraphEdgeList.h"
#include "GraphAdjMat.h"
using namespace std;

class GraphConverter{
public:
    GraphAdjList fromEdgeListToAdjList(GraphEdgeList& graphEdgeList);
    GraphEdgeList fromAdjListToEdgeList(GraphAdjList& graphAdjList);
    GraphAdjMat fromEdgeListToAdjMat(GraphEdgeList& graphEdgeList);
};
#endif // GRAPHCONVERTER_H
