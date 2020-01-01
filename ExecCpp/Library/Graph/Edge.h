#pragma once

class Edge {
public:
    explicit Edge(int cost, int to)
        :cost(cost), to(to)
    {}

    int getCost() const {
        return cost;
    }

    int getNext() const {
        return to;
    }

private:
    int cost;
    int to;
};
