#include <lib-algo-ds/graph/kruskalmst.h>
#include <lib-algo-ds/disjointset.h>

#include <functional>
#include <queue>
#include <vector>

using namespace graph;
using namespace std;

KruskalMST::KruskalMST(Graph const& g) {
    buildMST(g);
}

vector<Edge> KruskalMST::MST() const {
    return _mst;
}

void KruskalMST::buildMST(Graph const& g) {
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
    for (auto const& edge : g.edges()) {
        pq.push(edge);
    }

    DisjointSet ds(g.size());

    while (!pq.empty()) {
        auto const edge = pq.top();
        pq.pop();
        int v = edge.either();
        int w = edge.other(v);
        if (!ds.connected(v, w) && _mst.size() < g.size() - 1) {
            ds.connect(v, w);
            _mst.push_back(edge);
        } 
    }
}
