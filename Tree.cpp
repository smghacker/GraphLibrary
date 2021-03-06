#include "Tree.h"
#include <vector>
using namespace std;

Tree::Tree(int sz)
{
    treeParentList.resize(sz+1);
    this->sz = sz;
}

void Tree::build(istream& in)
{
    for(int i = 1; i <= sz; i++)
    {
        in >> treeParentList[i];
        if(treeParentList[i] == 0)
        {
            this->root = i;
        }
    }
}

int Tree::getRoot()const
{
    return this->root;
}

void Tree::add(int vertex)
{
    treeParentList.push_back(vertex);
    sz++;
}

void Tree::assignParent(int vertex, int parent)
{
    treeParentList[vertex] = parent;
}

bool Tree::isLeaf(int vertex)const
{
    for(int i = 1; i <= sz; i++)
    {
        if(treeParentList[i] == vertex)
        {
            return false;
        }
    }
    return true;
}

bool Tree::deleteIfLeaf(int vertex)
{
    if(isLeaf(vertex))
    {
        if(vertex != sz)
        {
            treeParentList[vertex] = treeParentList[sz];
        }
        sz--;
        treeParentList.erase(treeParentList.end());
        return true;
    }
    return false;
}

void Tree::printLeavesSlow(ostream& out)const
{
    for(int i = 1; i <= sz; i++)
    {
        if(isLeaf(i))
        {
            out << i << " ";
        }
    }
    out << endl;
}

void Tree::printLeaves(ostream& out)const
{
    int vertexes[sz+1];
    for(int i = 1; i <= sz; i++)
    {
        vertexes[i] = 0;
    }
    for(int i = 1; i <= sz; i++)
    {
        vertexes[treeParentList[i]]=1;//not leaf
    }
    for(int i = 1; i <= sz; i++)
    {
        if(vertexes[i]==0)
        {
            out << i << " ";
        }
    }
    out << endl;
}

void Tree::print(ostream& out)const
{
    for(int i = 1; i <= sz; i++)
    {
        out << "p(" << i << ") = " << treeParentList[i] << endl;
    }
    out << endl;
}
