| Phase | Topic |
|---|---|
| 1 | Graph fundamentals and terminology |
| 2 | Graph representations: adjacency matrix and adjacency list |
| 3 | Graph traversal: BFS and DFS |
| 4 | Cycle detection |
| 5 | Connected components |
| 6 | Shortest path algorithms |
| 7 | Minimum spanning trees |
| 8 | Topological sorting |
| 9 | Graph problems and coding practice |

# Graphs — Introduction and Fundamentals (C++)

## 1. What Is a Graph?

A **graph** is a non-linear data structure made up of:

- **Vertices (or nodes):** the individual items in the graph.
- **Edges:** the connections between pairs of vertices.

A graph is commonly represented mathematically as:

```text
G = (V, E)
```

Where:

- `G` represents the graph.
- `V` is the set of vertices.
- `E` is the set of edges.

Consider this graph:

```text
      0 -------- 1
      |          |
      |          |
      2 -------- 3 -------- 4
```

Its vertices and edges are:

```text
V = {0, 1, 2, 3, 4}

E = {(0, 1), (0, 2), (1, 3), (2, 3), (3, 4)}
```

For example, `(0, 1)` means that vertex `0` is connected to vertex `1`.

An edge represents a relationship or connection. It does not have to represent a physical road.

### Real-world examples

| Application | Vertices | Edges |
|---|---|---|
| Google Maps | Locations | Roads connecting locations |
| Social networks | People or accounts | Friendships, follows, or other relationships |
| Computer networks | Computers or routers | Network connections |
| Websites | Web pages | Links between pages |
| Airline networks | Airports | Flights between airports |

For example, in a social network, each person can be a vertex and a friendship can be an edge.

---

## 2. Graphs Compared with Linked Lists and Trees

You may already know linked lists and trees. Graphs generalize the idea of connecting nodes, but allow more flexible relationships.

### Linked list

A linked list usually connects nodes in a sequence:

```text
10 -> 20 -> 30 -> 40
```

Each node stores a link to another node, commonly the next node.

### Tree

A tree represents a hierarchy:

```text
        10
       /  \
      20   30
     / \
    40  50
```

It has a root, and its parent-child relationships do not form cycles.

### Graph

A graph can contain connections in many directions and between many different vertices:

```text
      0 -------- 1
      | \        |
      |  \       |
      2 -------- 3
```

Unlike a tree, a general graph:

- Does not need to have a root.
- Does not need to be hierarchical.
- Can contain cycles.
- Can have multiple different paths between two vertices.
- Can contain disconnected groups of vertices.

**Important relationship:** A tree is a special kind of graph. A tree is a connected, undirected graph with no cycles. A tree with `V` vertices has exactly `V - 1` edges.

Not every graph is a tree.

---

## 3. Types of Graphs

Graphs can be classified in several ways. These classifications describe different properties, so a graph can belong to more than one category at the same time.

### 3.1 Undirected graph

An **undirected graph** has edges without a direction. If vertex `A` is connected to vertex `B`, the connection can be followed in both directions.

```text
A -------- B
|          |
|          |
C -------- D
```

For an undirected edge, the connection between `A` and `B` is mutual:

```text
A -- B
```

It is not necessary to draw an arrow.

### 3.2 Directed graph

A **directed graph** (or **digraph**) has edges with a specific direction. An edge from `A` to `B` does not automatically mean that an edge from `B` to `A` exists.

```text
A -------> B
|
|
v
C
```

The edge `A -> B` means you can move from `A` to `B` by following that edge. It does not establish the reverse connection.

A social-media follow relationship is one example: one account can follow another without being followed back.

### 3.3 Unweighted graph

An **unweighted graph** does not assign a numerical cost or weight to its edges. For many basic problems, each edge is treated as one connection or one step.

```text
A -------- B
|          |
|          |
C -------- D
```

### 3.4 Weighted graph

A **weighted graph** assigns a value (a weight) to each edge.

```text
       A
      / \
   10/   \20
    /     \
   B---15--C
```

A weight can represent distance, time, cost, network latency, or another quantity. For example, an edge between two cities might have a weight representing the road distance in kilometres.

### 3.5 Connected and disconnected graphs

An undirected graph is **connected** when every vertex can be reached from every other vertex by following edges.

A graph is **disconnected** when at least one vertex cannot be reached from another. Its separate connected groups are called **connected components**.

Connected example:

```text
0 ----- 1 ----- 2
        |
        3
```

Disconnected example:

```text
0 ----- 1       2 ----- 3

4
```

Here, `{0, 1}`, `{2, 3}`, and `{4}` are separate connected components.

### 3.6 Cyclic and acyclic graphs

A **cycle** is a route that starts and ends at the same vertex, following edges along the way.

Example of a cycle:

```text
0 -------- 1
|          |
|          |
2 -------- 3
```

One cycle is:

```text
0 -> 1 -> 3 -> 2 -> 0
```

A graph containing at least one cycle is called **cyclic**. A graph with no cycles is called **acyclic**.

A **DAG** (Directed Acyclic Graph) is a directed graph that contains no directed cycle. DAGs are used in situations such as task scheduling and dependency management.

### 3.7 Simple graphs

A **simple graph** has no self-loops and no parallel (duplicate) edges.

- A **self-loop** is an edge from a vertex back to itself, such as `2 -> 2`.
- **Parallel edges** are multiple edges connecting the same pair of vertices.

Many introductory DSA problems use simple graphs, but always check the problem statement before assuming self-loops or repeated edges are impossible.

---

## 4. Important Graph Terminology

Use this graph for the examples in this section:

```text
      0 -------- 1
      |          |
      |          |
      2 -------- 3 -------- 4
```

| Term | Meaning |
|---|---|
| Vertex (node) | An individual item in a graph. |
| Edge | A connection between two vertices. |
| Adjacent vertices / neighbours | Vertices directly connected by an edge. |
| Degree | Number of edges incident to a vertex in an undirected graph. |
| Indegree | Number of directed edges entering a vertex. |
| Outdegree | Number of directed edges leaving a vertex. |
| Path | A sequence of vertices connected by edges. |
| Cycle | A path that returns to its starting vertex. |
| Connected graph | An undirected graph in which every vertex is reachable from every other vertex. |
| Connected component | A maximal connected group of vertices in an undirected graph. |

### 4.1 Degree in an undirected graph

The **degree** of a vertex is the number of edges connected to it.

For the example graph:

| Vertex | Neighbours | Degree |
|---|---|---:|
| 0 | 1, 2 | 2 |
| 1 | 0, 3 | 2 |
| 2 | 0, 3 | 2 |
| 3 | 1, 2, 4 | 3 |
| 4 | 3 | 1 |

Vertex `3` has degree `3` because it is connected to vertices `1`, `2`, and `4`.

For an undirected graph, the sum of all vertex degrees is twice the number of edges:

```text
Sum of degrees = 2 * E
```

This is because every undirected edge touches two vertices.

### 4.2 Indegree and outdegree in a directed graph

In a directed graph:

- **Indegree** is the number of edges entering a vertex.
- **Outdegree** is the number of edges leaving a vertex.

Consider:

```text
A -------> B
|
|
v
C
```

| Vertex | Indegree | Outdegree |
|---|---:|---:|
| A | 0 | 2 |
| B | 1 | 0 |
| C | 1 | 0 |

For a directed graph, the sum of all indegrees is equal to the sum of all outdegrees. Both sums equal the number of directed edges:

```text
Sum of indegrees = E
Sum of outdegrees = E
```

### 4.3 Path

A **path** is a sequence of vertices where each consecutive pair is connected by an edge.

For example:

```text
0 -> 1 -> 3 -> 4
```

This is a path from vertex `0` to vertex `4` in the example graph.

A path's length is often measured by its number of edges. In a weighted graph, the path's total weight is the sum of the weights of its edges.

### 4.4 Cycle

A **cycle** starts and ends at the same vertex. For example:

```text
0 -> 1 -> 3 -> 2 -> 0
```

This is a cycle in the example graph because it returns to vertex `0`.

---

## 5. Representing Graphs in C++

A graph needs a representation in memory so a program can store its vertices and edges. Two common representations are:

1. Adjacency matrix
2. Adjacency list

We will use **zero-based vertex numbering** in the examples, meaning that a graph with four vertices has vertex IDs `0`, `1`, `2`, and `3`.

Use this graph for both representations:

```text
      0 -------- 1
      |
      |
      2 -------- 3
```

Its undirected edges are:

```text
(0, 1)
(0, 2)
(2, 3)
```

### 5.1 Adjacency matrix

An **adjacency matrix** is a two-dimensional array (or vector) in which the entry at row `u`, column `v` records whether an edge from `u` to `v` exists.

For an unweighted graph, we commonly use:

- `1` if an edge exists.
- `0` if no edge exists.

For the example graph, the matrix is:

|   | 0 | 1 | 2 | 3 |
|---|---:|---:|---:|---:|
| **0** | 0 | 1 | 1 | 0 |
| **1** | 1 | 0 | 0 | 0 |
| **2** | 1 | 0 | 0 | 1 |
| **3** | 0 | 0 | 1 | 0 |

For example, `matrix[0][1]` is `1`, which means vertex `0` is connected to vertex `1`.

Because this is an undirected graph, the matrix is symmetric:

```text
matrix[u][v] = matrix[v][u]
```

#### C++ implementation

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int vertices = 4;

    // Create a vertices x vertices matrix filled with 0.
    vector<vector<int>> graph(vertices, vector<int>(vertices, 0));

    // Add undirected edges.
    graph[0][1] = 1;
    graph[1][0] = 1;

    graph[0][2] = 1;
    graph[2][0] = 1;

    graph[2][3] = 1;
    graph[3][2] = 1;

    // Print the adjacency matrix.
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}
```

We assign both `graph[u][v]` and `graph[v][u]` because an undirected edge works in both directions.

For a directed edge `u -> v`, update only:

```cpp
graph[u][v] = 1;
```

Do not update `graph[v][u]` unless the reverse edge also exists.

For a weighted graph, the matrix can store the edge's weight instead of `1`. Be careful when choosing a value to represent “no edge,” because `0` might be a valid edge weight in some problems.

### 5.2 Adjacency list

An **adjacency list** stores the neighbours of each vertex. In C++, a convenient implementation is a vector of vectors:

```cpp
vector<vector<int>> graph(vertices);
```

For the example graph, its adjacency list is:

```text
graph[0] -> [1, 2]
graph[1] -> [0]
graph[2] -> [0, 3]
graph[3] -> [2]
```

Each inner vector contains the neighbours of one vertex.

#### C++ implementation

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int vertices = 4;

    // Create one empty neighbour list for each vertex.
    vector<vector<int>> graph(vertices);

    // Add undirected edges.
    graph[0].push_back(1);
    graph[1].push_back(0);

    graph[0].push_back(2);
    graph[2].push_back(0);

    graph[2].push_back(3);
    graph[3].push_back(2);

    // Print the adjacency list.
    for (int i = 0; i < vertices; i++)
    {
        cout << i << " -> ";

        for (int neighbour : graph[i])
        {
            cout << neighbour << " ";
        }

        cout << '\n';
    }

    return 0;
}
```

#### Understanding `vector<vector<int>>`

This declaration:

```cpp
vector<vector<int>> graph(4);
```

creates an outer vector containing four initially empty inner vectors:

```text
graph[0] -> []
graph[1] -> []
graph[2] -> []
graph[3] -> []
```

This statement:

```cpp
graph[0].push_back(1);
```

adds `1` to the inner vector at index `0`:

```text
graph[0] -> [1]
```

The inner vectors grow as neighbours are added. You do not need to decide in advance how many neighbours each vertex will have.

For an undirected edge between `u` and `v`, add both directions:

```cpp
graph[u].push_back(v);
graph[v].push_back(u);
```

For a directed edge `u -> v`, add only the outgoing direction:

```cpp
graph[u].push_back(v);
```

### 5.3 Building an adjacency list from user input

Manually entering edges is fine for a small example, but real problems can contain hundreds or thousands of edges. We normally read the edges in a loop.

A common input format is:

```text
4 3
0 1
0 2
2 3
```

The first line means:

- `4` vertices.
- `3` edges.

Each following line contains the two endpoints of one edge.

#### C++ implementation for an undirected graph

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int vertices, edges;
    cin >> vertices >> edges;

    vector<vector<int>> graph(vertices);

    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;

        // Store both directions because the graph is undirected.
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // Print the adjacency list.
    for (int i = 0; i < vertices; i++)
    {
        cout << i << " -> ";

        for (int neighbour : graph[i])
        {
            cout << neighbour << " ";
        }

        cout << '\n';
    }

    return 0;
}
```

For the input above, the adjacency list is:

```text
0 -> 1 2
1 -> 0
2 -> 0 3
3 -> 2
```

For a **directed graph**, change the edge insertion inside the loop to:

```cpp
graph[u].push_back(v);
```

Do not insert the reverse edge unless it is separately present in the input.

> **Input assumption:** The code above assumes vertex IDs are in the range `0` to `vertices - 1`. If a problem numbers vertices from `1` to `vertices`, either allocate an extra slot or convert the input IDs to zero-based indexing.

### 5.4 Weighted adjacency list

For a weighted graph, each neighbour entry must store both the neighbouring vertex and the edge weight. A common C++ representation is:

```cpp
vector<vector<pair<int, int>>> graph(vertices);
```

Each pair stores:

```text
{neighbour, weight}
```

For an undirected weighted edge between vertex `u` and vertex `v` with weight `w`:

```cpp
graph[u].push_back({v, w});
graph[v].push_back({u, w});
```

For a directed weighted edge `u -> v` with weight `w`:

```cpp
graph[u].push_back({v, w});
```

Example:

```cpp
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int main()
{
    int vertices = 3;
    vector<vector<pair<int, int>>> graph(vertices);

    // Undirected weighted edge: 0 <-> 1 with weight 10.
    graph[0].push_back({1, 10});
    graph[1].push_back({0, 10});

    // Undirected weighted edge: 1 <-> 2 with weight 5.
    graph[1].push_back({2, 5});
    graph[2].push_back({1, 5});

    for (int u = 0; u < vertices; u++)
    {
        cout << u << " -> ";

        for (const auto& [neighbour, weight] : graph[u])
        {
            cout << "(" << neighbour << ", weight " << weight << ") ";
        }

        cout << '\n';
    }

    return 0;
}
```

The structured binding syntax `const auto& [neighbour, weight]` requires C++17. In earlier C++ versions, use `neighbour.first` and `neighbour.second` when iterating over each pair.

---

## 6. Adjacency Matrix vs. Adjacency List

Let:

- `V` = number of vertices.
- `E` = number of edges.
- `degree(u)` = number of neighbours of vertex `u` in an undirected graph.

| Operation / property | Adjacency matrix | Adjacency list |
|---|---|---|
| Main structure | 2D array or vector | Vector of neighbour lists |
| Space | `O(V²)` | `O(V + E)` |
| Check whether an edge exists | `O(1)` | `O(degree(u))` in the usual list representation |
| Iterate over all neighbours of `u` | `O(V)` | `O(degree(u))` |
| Add an edge | `O(1)` | Amortized `O(1)` per insertion with a vector |

### Sparse and dense graphs

A **sparse graph** has relatively few edges compared with the maximum possible number of edges. An adjacency list is usually more space-efficient for sparse graphs.

A **dense graph** has many edges, approaching the maximum possible number. An adjacency matrix can be practical for dense graphs and is useful when checking whether a particular edge exists frequently.

For a simple undirected graph with `V` vertices, the maximum number of edges is:

```text
V * (V - 1) / 2
```

For a simple directed graph without self-loops, the maximum number of edges is:

```text
V * (V - 1)
```

The adjacency list is commonly used in graph traversal and many coding-interview problems because it stores only existing edges.

---

## 7. Quick Complexity Reference

| Representation | Space complexity | Check edge `u -> v` | Iterate over neighbours of `u` |
|---|---:|---:|---:|
| Adjacency matrix | `O(V²)` | `O(1)` | `O(V)` |
| Adjacency list | `O(V + E)` | `O(degree(u))` | `O(degree(u))` |

For an undirected graph, every edge is normally stored twice in an adjacency list: once in each endpoint's neighbour list. This changes the constant factor, not the `O(V + E)` space complexity.

---

## 8. Key Things to Remember

1. A graph consists of vertices and edges: `G = (V, E)`.
2. An undirected edge can be followed in both directions; a directed edge has a specific direction.
3. A weighted graph stores a weight on each edge; an unweighted graph does not.
4. Degree counts incident edges in an undirected graph. Indegree and outdegree count incoming and outgoing edges in a directed graph.
5. A path connects vertices through edges. A cycle returns to its starting vertex.
6. A connected graph has a route between every pair of vertices. A disconnected graph has multiple connected components.
7. A tree is a connected, undirected, acyclic graph and has `V - 1` edges.
8. An adjacency matrix uses `O(V²)` space.
9. An adjacency list uses `O(V + E)` space.
10. In an undirected adjacency list, insert both directions. In a directed adjacency list, insert only the directed edge.

---

## 9. What Comes Next?

Once graph fundamentals and representations are clear, the next major topic is **graph traversal**: how to systematically visit vertices and explore their connections.

The two foundational traversal algorithms are:

- **Breadth-First Search (BFS):** explores the graph level by level and uses a queue.
- **Depth-First Search (DFS):** explores as far as possible along a path before backtracking; it is commonly implemented using recursion or a stack.

These algorithms are the foundation for many later graph problems, including connected components, cycle detection, and shortest paths.
