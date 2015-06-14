#include "Maze.h"
#include <vector>
#include <queue>

using namespace std;

Maze::Maze(int row, int col)
{
    maze.resize(row+2, vector<int>(col+2));
    this->row = row;
    this->col = col;
    for(int i = 0; i <= col+1; i++)
    {
        maze[0][i] = 1;
        maze[row+1][i] = 1;
    }
    for(int i = 0; i <= row+1; i++)
    {
        maze[i][0] = 1;
        maze[i][col+1] = 1;
    }
}

void Maze::read(istream& in)
{
    for(int i = 1; i <= row; i++)
    {
        for(int j = 1; j <= col; j++)
        {
            in >> maze[i][j];
        }
    }
}

bool Maze::isThereWay(int from, int to)const
{
    int n = (row+2)*(col+2);
    int used[n];
    int x, y;
    for(int i = 0; i < n; i++)
    {
        used[i] = 0;
    }
    queue<int> q;
    q.push(from);
    used[from] = 1;
    while(!q.empty())
    {
        x = q.front();
        q.pop();
        if(x == to)
        {
            return true;
        }
        for(int i = 1; i <= 4; i++)
        {
            switch(i)
            {
                case 1: y = x-1; break;
                case 2: y = x-col-2; break;
                case 3: y = x+1; break;
                case 4: y = x+col+2; break;
            }
            int rows = y/(col+2);
            int cols = y%(col+2);
            if(!used[y] && !maze[rows][cols])
            {
                used[y] = 1;
                q.push(y);
            }
        }
    }
    return false;
}
