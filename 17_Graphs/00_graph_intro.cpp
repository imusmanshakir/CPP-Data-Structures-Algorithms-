#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Graph {
  int V;
  vector<list<int>> l; // modern C++ approach using vector
  // or list<int> *l //dynamic memory allocation

public:
  Graph(int V) {
    this->V = V;
    l.resize(V);
    // or l = new list<int>[V];
  }
  void AddEdge(int u, int v) {
    l[u].push_back(v);
    l[v].push_back(u);
  }
  void printList() {
    for (int i = 0; i < V; i++) {
      cout << i << " : ";
      for (int neigh : l[i]) { // range-based for loop
        cout << neigh << "  ";
      }
      cout << endl;
    }
  }

  // ~Graph() { delete[] l; } // release memory(No need when using vector.
  // Vector manages memory auto)
};

int main() {
  Graph g(5);
  g.AddEdge(0, 1);
  g.AddEdge(1, 2);
  g.AddEdge(1, 3);
  g.AddEdge(2, 3);
  g.AddEdge(2, 4);

  g.printList();

  return 0;
};
