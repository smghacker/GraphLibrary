#include <iostream>
#include <cstdio>
#include"GraphConverter.h"
#include "GraphBuilder.h"
#include "Maze.h"
using namespace std;

int main()
{
    freopen("C:\\Users\\Sonia\\Desktop\\in.txt", "r", stdin);
   /* Matrix a(0);
    GraphConverter gc;
    GraphBuilder graphBuilder;

    GraphAdjList g = graphBuilder.buildGraphAdjList();
    g.print();
    Tree t = g.BFSSpanningTree(1);
    t.print(cout);*/

    /*Maze maze(4,4);
    maze.read(cin);
    if(maze.isWay(7,28))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }*/


    /*GridGraphAdjList graph(2,2,0);
    graph.makeGraph(cin);
    graph.print();*/

    /*GraphBuilder graphBuilder;
    GraphAdjList graph = graphBuilder.buildGraphAdjList();
    vector<int> vec = graph.findEulerLoop();
    for(int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }*/

    /*GraphBuilder graphBuilder;
    GraphAdjList graph = graphBuilder.buildGraphAdjList();
    Tree t = graph.DFSIterative(1);
    t.print(cout);
    Tree t1 = graph.DFS(1,0);
    t1.print(cout);
    graph.DFSStackTime(1);*/


    ///1 domashno konvertirane
    /*GraphEdgeList ge;
    Edge a1(1,2);
    Edge a2(2,3);
    Edge a3(1,3);
    ge.addEdge(a1);
    ge.addEdge(a2);
    ge.addEdge(a3);

    //Demonstrating conversion
    GraphAdjList a = gc.fromEdgeListToAdjList(ge);
    GraphEdgeList b = gc.fromAdjListToEdgeList(a);

    a.print();
    b.print();

    //Demonstrating building the graph
    GraphBuilder gb;
    GraphAdjList gcc = gb.buildGraphAdjList();
    gcc.print();
    GraphEdgeList gbb = gb.buildGraphEdgeList();
    gbb.print();*/

    ///2 domashno zada4a 1

    /*GraphEdgeList graph = graphBuilder.buildDirectedMultiGraphEdgeList();
    int length, u,v;
    cin >> u >> v >> length;
    GraphAdjMat graphAdjMat = gc.fromEdgeListToAdjMat(graph);
    cout << graphAdjMat.howManyPathsAreThereWithACertainLengthBetweenTwoVertices(length, u, v);*/


    ///2 domashno zada4a 2
    /*GraphEdgeList graph2 = graphBuilder.buildDirectedMultiGraphEdgeList();
    int u2,v2;
    cin >> u2 >> v2;
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
    return 0;
}
