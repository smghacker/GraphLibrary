#ifndef GRAPHEDGELIST_H
#define GRAPHEDGELIST_H
#include<vector>
#include<iostream>
#include "Edge.h"
using namespace std;

class GraphEdgeList{
private:
    vector<Edge> listOfEdges;
    bool directed;
    bool multi;
public:
    GraphEdgeList();
    GraphEdgeList(vector<Edge>& listOfEdges, bool directed, bool multi);
    bool isDirected()const;
    bool isMulti()const;
    vector<Edge> getEdges()const;
    void addEdge(Edge e);
    void print()const;
};
#endif
