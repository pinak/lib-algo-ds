#include <vector>
#include <lib-algo-ds/graph/primmmstlazy.h>

using namespace graph;
using namespace std;

PrimmMSTLazy::PrimmMSTLazy(Graph const& g) {
    buildMST(g);
}

vector<Edge> PrimmMSTLazy::MST() const {
    return _mst;
}

void PrimmMSTLazy::buildMST(Graph const& g) {
    EdgeMinPQ pq;
    for (auto const& edge : g.adjacent(0)) {
        pq.push(edge);
    }

    vector<bool> marked(g.size(), false);

    while (!pq.empty()) {
        auto current_edge = pq.top();
        pq.pop();
        auto const v = current_edge.either();
        auto const w = current_edge.other(v);
        if (marked[v] && marked[w]) {
            continue;
        }
        _mst.push_back(current_edge);

        if (!marked[v]) {
            visit(v, g, marked, pq);
        }

        if (!marked[w]) {
            visit(w, g, marked, pq);
        }
    }
}

void PrimmMSTLazy::visit(int vertex, Graph const& g, vector<bool>& marked, EdgeMinPQ& pq) {
    marked[vertex] = true;
    for (auto const& adj_edge : g.adjacent(vertex)) {
        if (!marked[adj_edge.other(vertex)]) {
            pq.push(adj_edge);
        }
    }
}