#include <bits/stdc++.h>
using namespace std;
void islandCount(int **edges, int n, int sv, bool *visited)
{
    visited[sv] = true;
    for (int i = 0; i < n; i++)
    {
        if (i == n)
            continue;
        if (edges[sv][i] == 1 && !visited[i])
        {
            islandCount(edges, n, i, visited);
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    int **edges = new int *[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }
    }
    for (int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            islandCount(edges, n, i, visited);
            count++;
        }
    }
    cout << "Total no. of Island: " << count << endl;
    return 0;
}