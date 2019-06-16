#pragma once

namespace graph {
class Edge {
public:
    Edge(int a, int b, double weight);

    int either() const;
    int other(int a) const;
    double weight() const;

    bool operator==(Edge const& other) const;
    bool operator!=(Edge const& other) const;
    bool operator<(Edge const& other) const;
    bool operator>(Edge const& other) const;


private:
    int _a;
    int _b;
    double _weight;
};
}