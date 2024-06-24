# <h1 align="center">Graph and Tree</h1>
<p align="center">Indy Aurellia Az Zahra</p>
<p align="center">2311110020</p>

### Graph
Graf adalah struktur data yang merupakan kombinasi dari simpul (node) dan sisi (edge). Simpul (vertex) menyimpan entitas, sementara sisi adalah koneksi antara dua simpul [1]. 

#### Jenis-jenis Graf

a. Graf Berarah dan Tak Berarah: Ketika dalam sebuah graf semua sisi menunjuk dari satu simpul ke simpul lainnya, graf yang terbentuk disebut Graf Berarah (Directed Graph). Sebaliknya, ketika ada garis sederhana antara dua simpul sebagai sisi, graf yang terbentuk disebut Graf Tak Berarah (Undirected Graph). [1]

b. Graf Bertimbang: Graf di mana setiap sisi memiliki bobot (nilai dari koneksi antara dua simpul yang dihubungkan oleh sisi tersebut). [1]

c. Graf Siklik dan Asiklik: Dalam kasus Graf Berarah, jika ada kemungkinan membuat jalur sedemikian rupa sehingga saat perjalanan berakhir pada simpul yang sudah pernah dikunjungi, graf tersebut disebut Graf Siklik (Cyclic Graph). Sebaliknya, graf disebut Graf Asiklik (Acyclic Graph) jika tidak ada kemungkinan tersebut. [1]

### Tree

Dalam Struktur Data Konsep Tree mirip seperti pohon yaitu kumpulan node yang saling terhubung satu sama lain dalam suatu kesatuan yang membentuk layaknya struktur sebuah pohon. Struktur Tree adalah suatu cara merepresentasikan suatu struktur hirarki ( one — to many ) secara grafis yang mirip sebuah pohon, walaupun pohon tersebut hanya tampak sebagai kumpulan — node — node dari atas ke bawah. Konsep Tree Di seuah struktur data yang tidak linier yang menggambarkan hubungan yang hirarkis ( one to many ) dan tidak linier antara elemen — elemennya. [2]


### Contoh Program Graph

```c++
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
```

#### Penjelasan Program Graph
- Graph Class: Kelas 'Graph' memiliki dua anggota: 'V' (jumlah simpul) dan 'adj' (array dari list untuk menyimpan adjacency list).
- Konstruktor: Menginisialisasi jumlah simpul dan mengalokasikan memori untuk adjacency list.
- addEdge: Menambahkan sisi antara dua simpul, karena ini adalah graph tidak berarah, maka menambahkan kedua arah.
- printGraph: Mencetak adjacency list dari setiap simpul

#### Output

```c++
Adjacency list of vertex 0
 head  -> 1 -> 4

Adjacency list of vertex 1
 head  -> 0 -> 2 -> 3 -> 4

Adjacency list of vertex 2
 head  -> 1 -> 3

Adjacency list of vertex 3
 head  -> 1 -> 2 -> 4

Adjacency list of vertex 4
 head  -> 0 -> 1 -> 3
```

Output menunjukkan adjacency list dari setiap simpul, yang menggambarkan hubungan antar simpul dalam graph.

### Conto Program Tree

```c++
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class BinaryTree {
public:
    Node* root;

    BinaryTree() { root = nullptr; }

    void inorderTraversal(Node* node) {
        if (node == nullptr)
            return;

        inorderTraversal(node->left);
        cout << node->data << " ";
        inorderTraversal(node->right);
    }
};

int main() {
    BinaryTree tree;
    tree.root = new Node(1);
    tree.root->left = new Node(2);
    tree.root->right = new Node(3);
    tree.root->left->left = new Node(4);
    tree.root->left->right = new Node(5);

    cout << "Inorder traversal of binary tree is: ";
    tree.inorderTraversal(tree.root);

    return 0;
}
```

#### Penjelasan Program Tree
- Node Class: Kelas 'Node' menyimpan data dan pointer ke anak kiri dan kanan.
- BinaryTree Class: Kelas 'BinaryTree' memiliki pointer ke root dari tree dan fungsi untuk traversal inorder.
- inorderTraversal: Fungsi rekursif untuk traversal inorder (kiri, akar, kanan).

#### Output Program

```c++
Inorder traversal of binary tree is: 4 2 5 1 3
```
Output menunjukkan traversal inorder dari binary tree, yaitu mengunjungi node kiri terlebih dahulu, kemudian node akar, dan terakhir node kanan.

#### Referensi

[1] V. Vashist, “Graphs Data Structure in C++,” Medium, Aug. 07, 2023. https://medium.com/@vinay.vashist2003/graphs-data-structure-in-c-ab7b4205f41a (accessed Jun. 20, 2024).

[2] D. Bali, “Memahami Konsep Tree dalam Struktur Data Lengkap dengan Source Code Programnya,” Medium, Jun. 14, 2021. https://daismabali.medium.com/memahami-konsep-tree-dalam-struktur-data-lengkap-dengan-source-code-programnya-acbd0a8733d6 (accessed Jun. 20, 2024).
