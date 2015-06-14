#ifndef GRAPHADJMAT_H
#define GRAPHADJMAT_H
#include "Matrix.h"
#include<vector>
#include<iostream>
using namespace std;

class GraphAdjMat{
private:
    Matrix* graph;
    int sz;
    bool directed;
    bool multi;
public:
    GraphAdjMat(Matrix* graph, bool directed, bool multi, int sz);
    int numPathsWithXLengthBetweenTwoVertices(long long length, int u, int v)const;
    bool isThereAPathBetweenTwoVertices(int u, int v)const;
};
#endif
