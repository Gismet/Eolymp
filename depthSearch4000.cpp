#include <iostream>
#include <algorithm>

// Problem:
/*Given a undirected unweighted graph, find the number of vertices in the connected component where the selected vertect s is in*/

void DFS(int **graph, int v, int n, int *visited)
{
    visited[v - 1] = 1;

    for (int i = 0; i < n; i++)
    {
        if (graph[v - 1][i] != 0 && visited[i] != 1)
        {
            DFS(graph, i + 1, n, visited);
        }
    }
}

int main()
{

    // getting inputs
    int n, s;
    std::cin >> n >> s; // this lines takes the number of vertices(labelled from 1 to n) and the selected vertex s

    // allocating memory for adjacency matrix of the graph
    int **graph = new int *[n];
    for (int i = 0; i < n; i++)
    {
        graph[i] = new int[n];
    }

    // bulding an adjacency matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cin >> graph[i][j];
        }
    }

    // allocating an array of size n to keep track of visited vertices
    int *visited = new int[n];
    // filling visited array with 0 just to be safe
    std::fill_n(visited, n, 0);

    // 0 indicates unvisited vertex
    // I used 1 to show the visited vertices. You can use boolean array of true and false. It doesn't matter

    // calling dfs function
    DFS(graph, s, n, visited);

    // Here I simply count the number of visited vertices in the visited[] array
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 1)
            count++;
    }

    std::cout << count;

    return 0;
}