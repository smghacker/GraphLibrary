#include "GraphAdjMat.h"
GraphAdjMat::GraphAdjMat(Matrix* graph, bool directed, bool multi, int sz)
{
    this->sz = sz;
    this->directed = directed;
    this->multi = multi;
    this->graph = graph;
}

int GraphAdjMat::numPathsWithXLengthBetweenTwoVertices(long long length, int u, int v)const
{
    if(length == 0 && u == v)
    {
        return 1;
    }
    else if(length == 0 && u!=v)
    {
        return 0;
    }

    Matrix matPowered=graph->fastMultiplication(length);
    return graph->get(u,v);
}

bool GraphAdjMat::isThereAPathBetweenTwoVertices(int u, int v)const
{
    bool isThereAPath = false;
    for(int i = 0; i < this->sz; i++)
    {
        if(numPathsWithXLengthBetweenTwoVertices(i, u, v))
        {
            isThereAPath = true;
            break;
        }
    }

    return isThereAPath;
}
