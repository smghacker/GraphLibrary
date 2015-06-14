#include <iostream>
#include <cstdio>
#include"GraphConverter.h"
#include "GraphBuilder.h"
#include "Maze.h"
using namespace std;

int main()
{
   /* GraphConverter gc;
    GraphEdgeList ge;
    Edge a1(1,2);
    Edge a2(2,3);
    Edge a3(1,3);
    ge.addEdge(a1);
    ge.addEdge(a2);
    ge.addEdge(a3);

    //Demonstrating conversion
    GraphAdjList a = gc.fromEdgeListToAdjList(ge);
    GraphEdgeList b = gc.fromAdjListToEdgeList(a);

    a.print(cout);
    b.print(cout);

    //Demonstrating building the graph
    GraphBuilder gb;
    GraphAdjList gcc = gb.buildGraphAdjList(cin, cout);
    gcc.print(cout);
    GraphEdgeList gbb = gb.buildGraphEdgeList(cin, cout);
    gbb.print(cout);*/

    /*GraphBuilder graphBuilder;
    GraphEdgeList graph = graphBuilder.buildDirectedMultiGraphEdgeList(cin, cout);
    int length, u,v;
    cin >> u >> v >> length;
    GraphConverter gc;
    GraphAdjMat graphAdjMat = gc.fromEdgeListToAdjMat(graph);
    cout << graphAdjMat.numPathsWithXLengthBetweenTwoVertices(length, u, v);*/


    /*GraphBuilder graphBuilder;
    GraphEdgeList graph2 = graphBuilder.buildDirectedMultiGraphEdgeList(cin, cout);
    int u2,v2;
    cin >> u2 >> v2;
    GraphConverter gc;
    GraphAdjMat graphAdjMat2 = gc.fromEdgeListToAdjMat(graph2);
    if(graphAdjMat2.isThereAPathBetweenTwoVertices(u2,v2)){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    if(graphAdjMat2.isThereAPathBetweenTwoVertices(v2,u2)){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }*/

    /*Matrix a(0);
    GraphConverter gc;
    GraphBuilder graphBuilder;
    GraphAdjList g = graphBuilder.buildGraphAdjList(cin, cout);
    g.print(cout);
    Tree t = g.BFSSpanningTree(1);
    t.print(cout);*/

    /*Maze maze(4,4);
    maze.read(cin);
    if(maze.isThereWay(7,28))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }*/


    /*GridGraphAdjList graph(2,2,0);
    graph.makeGraph(cin, cout);
    graph.print(cout);*/

    /*GraphBuilder graphBuilder;
    GraphAdjList graph = graphBuilder.buildGraphAdjList(cin, cout);
    vector<int> vec = graph.findEulerLoop();
    for(int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }*/

    /*GraphBuilder graphBuilder;
    GraphAdjList graph = graphBuilder.buildGraphAdjList(cin, cout);
    Tree t = graph.DFSIterative(1);
    t.print(cout);
    Tree t1 = graph.DFS(1,0);
    t1.print(cout);
    graph.DFSStackTime(1, cout);*/

    return 0;
}
