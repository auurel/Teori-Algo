#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Graph {
    int V; // Jumlah simpul (vertices)
    vector<list<int>> adj; // Pointer ke array yang menyimpan adjacency list

public:
    Graph(int V); // Konstruktor

    void addEdge(int v, int w); // Menambahkan sisi ke graph
    void printGraph(); // Mencetak graph
};

Graph::Graph(int V) {
    this->V = V;
    adj.resize(V);
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w); // Tambahkan w ke list v
    adj[w].push_back(v); // Tambahkan v ke list w karena ini adalah graph tidak berarah
}

void Graph::printGraph() {
    for (int v = 0; v < V; ++v) {
        cout << "\nAdjacency list of vertex " << v << "\n head ";
        for (auto x : adj[v])
            cout << " -> " << x;
        printf("\n");
    }
}

int main() {
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.printGraph();

    return 0;
}
