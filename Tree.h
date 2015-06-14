#ifndef Tree_h
#define Tree_h
#include<iostream>
#include<vector>
using namespace std;

class Tree
{
private:
    vector<int> treeParentList;
    int sz;
    int root;
public:
    Tree(int sz);
    void build(istream& in);
    int getRoot()const;
    void add(int vertex);
    void assignParent(int vertex, int parent);
    bool isLeaf(int vertex)const;
    bool deleteIfLeaf(int vertex);
    void printLeavesSlow(ostream& out)const;
    void printLeaves(ostream& out)const;
    void print(ostream& out)const;
};

#endif

