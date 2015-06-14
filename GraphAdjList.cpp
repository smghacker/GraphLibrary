#include "GraphAdjList.h"
#include <queue>
#include <stack>
#include <algorithm>

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

void GraphAdjList::print(ostream& out)
{
    for(int i = 0; i < sz; i++)
    {
        out << i <<  " :";
        for(int j = 0; j < graph[i].size(); j++)
        {
            out << " " << graph[i][j];
        }
        out << endl;
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
    for(int i = 0; i < sz; i++)
    {
        used[i] = 0;
    }
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

vector<int> GraphAdjList::parents()
{
    vector<int> par;
    par.assign(sz,0);
    for(int i = 1; i < sz; i++)
    {
        for(int j = 0; j < graph[i].size(); j++)
        {
            int to = graph[i][j];
            par[to]++;
        }
    }
    return par;
}

bool GraphAdjList::isConnected()
{
    int used[sz];
    for(int i = 0; i < sz; i++)
    {
        used[i] = 0;
    }
    queue<int> q;
    q.push(1);
    used[1] = 1;
    while(!q.empty())
    {
        int curr = q.front();
        q.pop();
        for(int i = 0; i < graph[curr].size(); i++)
        {
            if(!used[graph[curr][i]])
            {
                q.push(graph[curr][i]);
                used[graph[curr][i]] = 1;
            }
        }
    }
    for(int i = 1; i < sz; i++)
    {
        if(used[i] == 0)
        {
            return false;
        }
    }
    return true;
}

bool GraphAdjList::isThereEulerLoop()
{
    if(!isConnected())
    {
        return false;
    }
    if(isDirected())
    {
        vector<int> par = parents();
        for(int i = 1; i < par.size(); i++)
        {
            if(graph[i].size() != par[i])
            {
                return false;
            }
        }
        return true;
    }
    else
    {
        for(int i = 1; i < sz; i++)
        {
            if(graph[i].size() % 2)
            {
                return false;
            }
        }
    }

    return true;
}

bool GraphAdjList::isThereEulerPath()
{
    if(!isConnected())
    {
        return false;
    }
    if(isDirected())
    {
        vector<int> par = parents();
        int cnt = 0;
        int bigger = 0;
        int smaller = 0;
        for(int i = 1; i < par.size(); i++)
        {
            if(graph[i].size() > par[i])
            {
                bigger++;
            }
            else if(graph[i].size() < par[i])
            {
                smaller++;
            }
        }
        if((bigger == smaller && bigger == 1) || isThereEulerLoop())
        {
            return true;
        }
        return false;
    }
    else
    {
        int odd = 0;
        for(int i = 1; i < sz; i++)
        {
            if(graph[i].size() % 2)
            {
                odd++;
            }
        }
        if(odd == 0 || odd == 2)
        {
            return true;
        }
        return false;
    }
}

vector<int> GraphAdjList::findEulerLoop()
{
    vector<int> res;
    if(!isThereEulerLoop())
    {
        return res;
    }
    int nextEdge[sz];
    for(int i = 1; i < sz; i++)
    {
        nextEdge[i] = 0;
    }
    stack<int> vert;
    vert.push(1);
    while(!vert.empty())
    {
        int curr = vert.top();
        if(nextEdge[curr] < graph[curr].size())
        {
            int next = graph[curr][nextEdge[curr]];
            vert.push(next);
            nextEdge[curr]++;
            if(!isDirected())
            {
                vector<int>::iterator it = graph[next].begin();
                while(*it != curr)
                {
                    it++;
                }
                graph[next].erase(it);
            }
        }
        else
        {
            res.push_back(curr);
            vert.pop();
        }
    }
    reverse(res.begin(), res.end());
    return res;
}

Tree GraphAdjList::DFSIterative(int vertex)
{
    Tree spanningTree(sz-1);
    int used[sz];
    int next[sz];
    for(int i = 0; i < sz; i++)
    {
        used[i] = 0;
        next[i] = 0;
    }
    stack<int> vert;
    vert.push(vertex);
    used[vertex] = 1;
    spanningTree.assignParent(vertex, 0);
    while(!vert.empty())
    {
        int curr = vert.top();
        if(next[curr] < graph[curr].size())
        {
            int v = graph[curr][next[curr]];
            next[curr]++;
            if(!used[v])
            {
                vert.push(v);
                used[v] = 1;
                spanningTree.assignParent(v, curr);
            }
        }
        else
        {
            vert.pop();
        }
    }
    return spanningTree;
}

void GraphAdjList::DFSInner(int vertex, int parent, vector<int>& used, Tree& spanningTree)
{
    spanningTree.assignParent(vertex, parent);
    used[vertex] = 1;
    for(int i = 0; i < graph[vertex].size(); i++)
    {
        int next = graph[vertex][i];
        if(!used[next])
        {
            DFSInner(next, vertex, used, spanningTree);
        }
    }
}

Tree GraphAdjList::DFS(int vertex, int parent)
{
    vector<int> used;
    used.assign(sz,0);
    Tree spanningTree(sz-1);
    DFSInner(vertex, parent, used, spanningTree);
    return spanningTree;
}

void GraphAdjList::DFSStackTime(int vertex, ostream& out)
{
    vector<int> addStack;
    vector<int> deleteStack;
    int used[sz];
    int next[sz];
    for(int i = 0; i < sz; i++)
    {
        used[i] = 0;
        next[i] = 0;
    }
    stack<int> vert;
    vert.push(vertex);
    addStack.push_back(vertex);
    used[vertex] = 1;
    while(!vert.empty())
    {
        int curr = vert.top();
        if(next[curr] < graph[curr].size())
        {
            int v = graph[curr][next[curr]];
            next[curr]++;
            if(!used[v])
            {
                vert.push(v);
                addStack.push_back(v);
                used[v] = 1;
            }
        }
        else
        {
            vert.pop();
            deleteStack.push_back(curr);
        }
    }
    out << "The elements enter the stack in this order:" << endl;
    for(int i = 0; i < addStack.size(); i++)
    {
        out << addStack[i] << " ";
    }
    out << endl;
    out << "The elements exit the stack in this order:" << endl;
    for(int i = 0; i < addStack.size(); i++)
    {
        out << deleteStack[i] << " ";
    }
    out << endl;
}
