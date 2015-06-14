#include "GraphEdgeList.h"

GraphEdgeList::GraphEdgeList()
{
    this->directed = false;
    this->multi = false;
}

GraphEdgeList::GraphEdgeList(vector<Edge>& listOfEdges, bool directed, bool multi)
{
    this->listOfEdges = listOfEdges;
    this->directed = directed;
    this->multi = multi;
}

bool GraphEdgeList::isDirected()const
{
    return directed;
}

bool GraphEdgeList::isMulti()const
{
    return multi;
}

vector<Edge> GraphEdgeList::getEdges()const
{
    return listOfEdges;
}

void GraphEdgeList::addEdge(Edge e)
{
    this->listOfEdges.push_back(e);
}

void GraphEdgeList::print(ostream& out)const
{
    for(int i = 0; i < listOfEdges.size(); i++)
    {
        out << listOfEdges[i].getBegin() << " " << listOfEdges[i].getEnd() << endl;
    }
}


