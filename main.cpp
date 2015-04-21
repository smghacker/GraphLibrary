#include <iostream>
#include"GraphConverter.h"
#include "GraphBuilder.h"
using namespace std;

int main()
{
    Matrix a(0);
    GraphConverter gc;
    GraphBuilder graphBuilder;
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
