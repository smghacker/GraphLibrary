#ifndef GRAPHADJLIST_H
#define GRAPHADJLIST_H
#include<vector>
#include<iostream>
#include "Tree.h"
using namespace std;

class GraphAdjList{
private:
    vector<vector<int> > graph;
    int sz;
    bool directed;
    bool multi;
    void DFSInner(int vertex, int parent, vector<int>& usedDFS, Tree& spanningTreeDFS)const;
public:
    GraphAdjList();
    GraphAdjList(vector<vector<int> >& graph, bool directed, bool multi);

    void print(ostream& out)const;
    vector<vector<int> > getGraph()const;
    bool isDirected()const;
    bool isMulti()const;

    Tree BFSSpanningTree(int vertex)const;
    vector<int> parents()const;
    bool isConnected()const;
    bool isThereEulerLoop()const;
    bool isThereEulerPath()const;
    vector<int> findEulerLoop()const;
    Tree DFSIterative(int vertex)const;
    Tree DFS(int vertex, int parent)const;
    void DFSStackTime(int vertex, ostream& out)const;
};
#endif // GRAPHADJLIST_H
