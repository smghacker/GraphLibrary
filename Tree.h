#ifndef Tree_h
#define Tree_h
#include<iostream>
#include<vector>
using namespace std;

class Tree{
private:
    vector<int> treeParentList;

    int sz;
    int root;
public:
    Tree(int sz);
    void build(istream& in);
    int getRoot();
    void add(int vertex);
    void assignParent(int vertex, int parent);
    bool isLeaf(int vertex);
    bool deleteIfLeaf(int vertex);
    void slowGetLeaves(ostream& out);
    void getLeaves(ostream& out);
};

#endif

