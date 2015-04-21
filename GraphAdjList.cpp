#include "GraphAdjList.h"

GraphAdjList::GraphAdjList()
{
    this->sz = 0;
    this->directed = false;
    this->multi = false;
}

GraphAdjList::GraphAdjList(vector<vector<int> >& graph, bool directed, bool multi)
{
    this->sz = graph.size();
    this->graph = graph;
    this->directed = directed;
    this->multi = multi;
}

void GraphAdjList::print()
{
    for(int i = 0; i < sz; i++)
    {
        cout << i <<  " :";
        for(int j = 0; j < graph[i].size(); j++)
        {
            cout << " " << graph[i][j];
        }
        cout << endl;
    }
}

vector<vector<int> > GraphAdjList::getGraph()const
{
    return graph;
}

bool GraphAdjList::isDirected()const
{
    return directed;
}

bool GraphAdjList::isMulti()const
{
    return multi;
}
