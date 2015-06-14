#ifndef Maze_h
#define Maze_h
#include<iostream>
#include<vector>
#include "GridGraphAdjList.h"
using namespace std;

class Maze{
private:
    vector<vector<int> > maze;
    int row;
    int col;
public:
    Maze(int r, int c);
    void read(istream& in);
    bool isWay(int from, int to);
};

#endif
