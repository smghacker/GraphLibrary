#include "GraphBuilder.h"


GraphAdjList GraphBuilder::buildGraphAdjList(istream& in, ostream& out)
{
    int numOfVertices;
    out << "Type number of vertices" << endl;
    in >> numOfVertices;
    bool isDirected;
    out << "Type 1 if it is directed and 0 if it is not" << endl;
    in >> isDirected;
    bool isMulti;
    out << "Type 1 if the graph is multigraph and 0 if it is not" << endl;
    in >> isMulti;

    int numOfEdges;
    out << "Type the number of edges and then type the edges " << endl;
    in >> numOfEdges;

    vector<vector<int> > graph(numOfVertices+1);
    for(int i = 0; i < numOfEdges; i++)
    {
        int from,to;
        in >> from >> to;
        graph[from].push_back(to);
        if(!isDirected)
        {
            graph[to].push_back(from);
        }
    }

    return GraphAdjList(graph, isDirected, isMulti);
}

GraphEdgeList GraphBuilder::buildGraphEdgeList(istream& in, ostream& out)
{
    int numOfVertices;
    out << "Type number of vertices" << endl;
    in >> numOfVertices;
    bool isDirected;
    out << "Type 1 if it is directed and 0 if it is not" << endl;
    in >> isDirected;
    bool isMulti;
    out << "Type 1 if the graph is multigraph and 0 if it is not" << endl;
    in >> isMulti;

    int numOfEdges;
    out << "Type the number of edges and then type the edges" << endl;
    in >> numOfEdges;

    vector<Edge> graph;
    for(int i = 0; i < numOfEdges; i++)
    {
        int from,to;
        in >> from >> to;
        Edge edge(from, to);
        if(!isDirected)
        {
            Edge edge1(to,from);
            graph.push_back(edge1);
        }
        graph.push_back(edge);
    }

    return GraphEdgeList(graph, isDirected, isMulti);
}

GraphEdgeList GraphBuilder::buildDirectedMultiGraphEdgeList(istream& in, ostream& out)
{
    int numOfVertices;
    out << "Type number of vertices" << endl;
    in >> numOfVertices;
    int numOfEdges;
    out << "Type the number of edges and then type the edges" << endl;
    in >> numOfEdges;

    vector<Edge> graph;
    for(int i = 0; i < numOfEdges; i++)
    {
        int from,to;
        in >> from >> to;
        Edge edge(from, to);
        graph.push_back(edge);
    }

    return GraphEdgeList(graph, true, true);
}
