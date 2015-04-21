#include "Edge.h"

Edge::Edge(int begin, int end)
{
    this->begin = begin;
    this->end = end;
    this->weight = 1;
}

Edge::Edge(int begin, int end, int weight)
{
    this->begin = begin;
    this->end = end;
    this.weight = weight;
}

int Edge::getBegin()const
{
    return begin;
}

int Edge::getEnd()const
{
    return end;
}

int Edge::getWeight()const
{
    return weight;
}
