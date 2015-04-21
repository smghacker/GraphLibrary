#ifndef EDGE_H
#define EDGE_H
class Edge{
private:
    int begin;
    int end;
    int weight;
public:
    Edge(int begin, int end);
    Edge(int begin, int end, int weight);
    int getBegin()const;
    int getEnd()const;
    int getWeight()const;
};
#endif // EDGE_H
