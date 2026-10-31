#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int vertices = 4;

    vector<vector<int>> graph(vertices, vector<int>(vertices, 0));

    // Add undirected edges
    graph[0][1] = 1;
    graph[1][0] = 1;

    graph[0][2] = 1;
    graph[2][0] = 1;

    graph[2][3] = 1;
    graph[3][2] = 1;

    // Print adjacency matrix
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            cout << graph[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}
