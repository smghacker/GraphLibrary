#include "GraphBuilder.h"


GraphAdjList GraphBuilder::buildGraphAdjList()
{
    int numOfVertices;
    cout << "Type number of vertices" << endl;
    cin >> numOfVertices;
    bool isDirected;
    cout << "Type 1 if it is directed and 0 if it is not" << endl;
    cin >> isDirected;
    bool isMulti;
    cout << "Type 1 if the graph is multigraph and 0 if it is not" << endl;
    cin >> isMulti;

    int numOfEdges;
    cout << "Type the number of edges and then type the edges " << endl;
    cin >> numOfEdges;

    vector<vector<int> > graph(numOfVertices);
    for(int i = 0; i < numOfEdges; i++)
    {
        int from,to;
        cin >> from >> to;
        graph[from].push_back(to);
        if(!isDirected)
        {
            graph[to].push_back(from);
        }
    }

    return GraphAdjList(graph, isDirected, isMulti);
}

GraphEdgeList GraphBuilder::buildGraphEdgeList()
{
    int numOfVertices;
    cout << "Type number of vertices" << endl;
    cin >> numOfVertices;
    bool isDirected;
    cout << "Type 1 if it is directed and 0 if it is not" << endl;
    cin >> isDirected;
    bool isMulti;
    cout << "Type 1 if the graph is multigraph and 0 if it is not" << endl;
    cin >> isMulti;

    int numOfEdges;
    cout << "Type the number of edges and then type the edges" << endl;
    cin >> numOfEdges;

    vector<Edge> graph;
    for(int i = 0; i < numOfEdges; i++){
        int from,to;
        cin >> from >> to;
        Edge edge(from, to);
        if(!isDirected){
            Edge edge1(to,from);
            graph.push_back(edge1);
        }
        graph.push_back(edge);
    }

    return GraphEdgeList(graph, isDirected, isMulti);
}

GraphEdgeList GraphBuilder::buildDirectedMultiGraphEdgeList()
{
    int numOfVertices;
    cin >> numOfVertices;
    int numOfEdges;
    cin >> numOfEdges;

    vector<Edge> graph;
    for(int i = 0; i < numOfEdges; i++){
        int from,to;
        cin >> from >> to;
        Edge edge(from, to);
        graph.push_back(edge);
    }

    return GraphEdgeList(graph, true, true);
}
