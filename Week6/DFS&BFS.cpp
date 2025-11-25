#include <iostream>
using namespace std;

struct Node {
    int v;
    Node* next;
};

#define MAX 100

class Graph {
public:
    int V;
    Node* adj[MAX];

    Graph(int n) {
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
};

void DFS_Util(Graph &g, int u, bool visited[]) {
    visited[u] = true;
    cout << u << " ";

    Node* cur = g.adj[u];
    while (cur) {
        int v = cur->v;
        if (!visited[v])
            DFS_Util(g, v, visited);
        cur = cur->next;
    }
}

void DFS(Graph &g, int start) {
    bool visited[MAX] = {false};
    DFS_Util(g, start, visited);
}

void BFS(Graph &g, int start) {
    bool visited[MAX] = {false};
    int queue[MAX];
    int head = 0, tail = 0;

    queue[tail++] = start;
    visited[start] = true;

    while (head < tail) {
        int u = queue[head++];
        cout << u << " ";

        Node* cur = g.adj[u];
        while (cur) {
            int v = cur->v;
            if (!visited[v]) {
                visited[v] = true;
                queue[tail++] = v;
            }
            cur = cur->next;
        }
    }
}

int main() {
    Graph g(6);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(1,4);
    g.addEdge(2,5);

    cout << "DFS: ";
    DFS(g, 0);

    cout << "\nBFS: ";
    BFS(g, 0);

    return 0;
}
