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
    void DFSInner(int vertex, int parent, vector<int>& usedDFS, Tree& spanningTreeDFS);
public:
    GraphAdjList();
    GraphAdjList(vector<vector<int> >& graph, bool directed, bool multi);
    void print(ostream& out);
    vector<vector<int> > getGraph()const;
    bool isDirected()const;
    bool isMulti()const;
    Tree BFSSpanningTree(int vertex);
    vector<int> parents();
    bool isConnected();
    bool isThereEulerLoop();
    bool isThereEulerPath();
    vector<int> findEulerLoop();
    Tree DFSIterative(int vertex);
    Tree DFS(int vertex, int parent);
    void DFSStackTime(int vertex, ostream& out);
};
#endif // GRAPHADJLIST_H
