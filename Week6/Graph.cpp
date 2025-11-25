#include <iostream>
using namespace std;

struct Node {
    int v;
    Node* next;
};

#define MAX 100

class GraphList {
public:
    int V;
    Node* adj[MAX];   

    GraphList(int n) {
        V = n;
        for (int i = 0; i < V; i++)
            adj[i] = NULL;
    }

    void addEdge(int u, int v) {
        Node* nodeV = new Node{v, adj[u]};
        adj[u] = nodeV;

        Node* nodeU = new Node{u, adj[v]};
        adj[v] = nodeU;
    }

    void print() {
        for (int i = 0; i < V; i++) {
            cout << i << ": ";
            Node* cur = adj[i];
            while (cur) {
                cout << cur->v << " ";
                cur = cur->next;
            }
            cout << endl;
        }
    }
};

int main() {
    GraphList g(5);
    g.addEdge(0,1);
    g.addEdge(0,4);
    g.addEdge(1,2);
    g.addEdge(1,3);

    g.print();
}
