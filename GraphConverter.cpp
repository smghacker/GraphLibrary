#include "GraphConverter.h"

GraphAdjList GraphConverter::fromEdgeListToAdjList(GraphEdgeList& graphEdgeList)
{
    vector<vector<int> > graphAdjList;
    vector<Edge> edges = graphEdgeList.getEdges();
    int max1 = -1;
    for(int i = 0; i < edges.size(); i++)
    {
        max1 = max(max1, edges[i].getBegin());
        max1 = max(max1, edges[i].getEnd());
    }
    graphAdjList.resize(max1 + 1);
    bool directed = graphEdgeList.isDirected();
    for(int i = 0; i < edges.size(); i++)
    {
        int beg = edges[i].getBegin();
        int end = edges[i].getEnd();
        graphAdjList[beg].push_back(end);
        if(!directed)
        {
            graphAdjList[end].push_back(beg);
        }
    }
    bool multi = graphEdgeList.isMulti();
    return GraphAdjList(graphAdjList, directed, multi);
}

GraphEdgeList GraphConverter::fromAdjListToEdgeList(GraphAdjList& graphAdjList)
{
    vector<Edge> edges;
    vector<vector<int> > adjList = graphAdjList.getGraph();

    for(int i = 0; i < adjList.size(); i++)
    {
        int begin = i;
        for(int j = 0; j < adjList[i].size(); j++)
        {
            int end = adjList[i][j];
            Edge edge(begin, end);
            edges.push_back(edge);
        }
    }

    bool directed = graphAdjList.isDirected();
    bool multi  = graphAdjList.isMulti();

    return GraphEdgeList(edges, directed, multi);
}

GraphAdjMat GraphConverter::fromEdgeListToAdjMat(GraphEdgeList& graphEdgeList)
{
    vector<vector<int> > graphAdjMat;
    vector<Edge> edges = graphEdgeList.getEdges();
    int max1 = -1;
    for(int i = 0; i < edges.size(); i++)
    {
        max1 = max(max1, edges[i].getBegin());
        max1 = max(max1, edges[i].getEnd());
    }
    graphAdjMat.resize(max1 + 1);
    for(int i = 0; i < max1 + 1; i++)
    {
        graphAdjMat[i].resize(max1 + 1);
    }

    for(int i = 0; i < edges.size(); i++)
    {
        int beg = edges[i].getBegin();
        int end = edges[i].getEnd();

        graphAdjMat[beg][end]++;
    }

    bool directed = graphEdgeList.isDirected();
    bool multi  = graphEdgeList.isMulti();
    Matrix matrix(graphAdjMat, graphAdjMat.size());
    Matrix* graphAdjMatrix = &matrix;
    return GraphAdjMat(graphAdjMatrix, directed, multi, max1+1);
}

