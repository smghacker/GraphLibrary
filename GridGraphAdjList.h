#ifndef GRIDGRAPHADJLIST_H
#define GRIDGRAPHADJLIST_H
#include<vector>
#include<iostream>
using namespace std;

class GridGraphAdjList{
private:
    vector<vector<int> > adjList;
    int MAXG = 100000;
    int MAXD = 5;
    int row = 0;
    int col = 0;
    bool directed;
    vector<vector<int> > readTable(istream& in, ostream& out);
public:
    GridGraphAdjList();
    GridGraphAdjList(int row, int col, bool directed);
    void print(ostream& out);
    vector<vector<int> > getGraph()const;
    bool isDirected()const;
    void addEdge(int from, int to);
    void makeGraph(istream& in, ostream& out);
};
#endif // GRAPHADJLIST_H

