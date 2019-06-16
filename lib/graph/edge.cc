#include <lib-algo-ds/graph/edge.h>

using namespace graph;

Edge::Edge(int a, int b, double weight)
    : _a{a},
      _b{b},
      _weight{weight} {
};

int Edge::either() const {
    return _a;
}

int Edge::other(int a) const {
    if (a == _a) {
        return _b;
    } else {
        return _a;
    }
}

double Edge::weight() const {
    return _weight;
}

bool Edge::operator==(Edge const& other) const {
    return _weight == other._weight;
}

bool Edge::operator<(Edge const& other) const {
    return _weight < other._weight;
}

bool Edge::operator>(Edge const& other) const {
    return !(*this < other) && *this != other;
}

bool Edge::operator!=(Edge const& other) const {
    return !(*this == other);
}