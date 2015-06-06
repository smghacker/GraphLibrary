#include "GraphAdjList.h"
#include <cstring>
#include <queue>

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

Tree GraphAdjList::BFSSpanningTree(int vertex)
{
    Tree spanningTree(sz-1);
    int used[sz];
    memset(used, 0, sizeof(used));
    used[vertex] = 1;
    queue<int> q;
    q.push(vertex);
    while(!q.empty())
    {
        int current = q.front();
        q.pop();
        for(int i = 0; i < graph[current].size(); i++)
        {
            int next = graph[current][i];
            if(!used[next])
            {
                q.push(next);
                used[next] = 1;
                spanningTree.assignParent(next, current);
            }
        }
    }
    return spanningTree;
}
