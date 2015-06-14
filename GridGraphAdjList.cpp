#include "GridGraphAdjList.h"
GridGraphAdjList::GridGraphAdjList(int row, int col, bool directed)
{
    this->row = row;
    this->col = col;
    adjList.resize(MAXG, vector<int>(MAXD, 0));
    this->directed = directed;
}

void GridGraphAdjList::print(ostream& out)const
{
    for(int i = 0; i < (row+2)*(col+2) ; i++)
    {
        for(int j = 0; j < MAXD; j++)
        {
            out << adjList[i][j] << " ";
        }
        out << endl;
    }
}

vector<vector<int> > GridGraphAdjList::getGraph()const
{
    return adjList;
}

bool GridGraphAdjList::isDirected()const
{
    return directed;
}

void GridGraphAdjList::addEdge(int from, int to)
{
    int adj;
    adj = adjList[from][0] + 1;
    ++adjList[from][0];
    adjList[from][adj] = to;
    adj = adjList[to][0] + 1;
    ++adjList[to][0];
    adjList[to][adj] = from;
}

vector<vector<int> > GridGraphAdjList::readTable(istream& in, ostream& out)
{
    vector<vector<int> > matr;
    matr.resize(row+2, vector<int>(col+2));
    out << "Input the table: " << endl;
    for(int i = 1; i <= row; i++)
    {
        for(int j = 1; j <= col; j++)
        {
            in >> matr[i][j];
        }
    }
    for(int i = 0; i <= row; i++)
    {
        matr[i][0] = 1;
        matr[i][col+1] = 1;
    }
    for(int i = 0; i <= col; i++)
    {
        matr[0][i] = 1;
        matr[row+1][i] = 1;
    }
    return matr;
}

void GridGraphAdjList::makeGraph(istream& in, ostream& out)
{
    vector<vector<int> > maze = readTable(in, out);
    const int lim = row*(col+2)+col+2;
    int used[lim];
    for(int i = 0; i < lim; i++)
    {
        used[i] = 0;
    }
    for(int i = 1; i <= row; i++)
    {
        for(int j = 1; j <= col; j++)
        {
            if(!maze[i][j])
            {
                int k = i*(col+2)+j;
                used[k] = 1;
                if(!maze[i][j-1] && !used[k-1])
                {
                    used[k-1] = 1;
                    addEdge(k, k-1);
                }
                if(!maze[i-1][j] && !used[k-col-2])
                {
                    used[k-col-2] = 1;
                    addEdge(k, k-col-2);
                }
                if(!maze[i][j+1] && !used[k+1])
                {
                    used[k+1] = 1;
                    addEdge(k, k+1);
                }
                if(!maze[i+1][j] && !used[k+col+2])
                {
                    used[k+col+2] = 1;
                    addEdge(k, k+col+2);
                }
            }
        }
    }
}
