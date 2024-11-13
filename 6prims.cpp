#include <bits/stdc++.h>
using namespace std;

vector<int> a;
vector<vector<int>> mat;
vector<vector<int>> weight;
vector<int> visited;
vector<int> mst;

const int inf = INT_MAX;
void prims(int d)
{
    cout << "PRIMS" << endl;
    cout<<"MST: "<<endl;
    visited[d] = 1;
    mst.push_back(a[d]);
    int num_vertices = a.size();

    while (mst.size() < num_vertices)
    {
        int min_weight = inf;
        int start, end;

        for (int i = 0; i < num_vertices; i++)
        {
            if (visited[i] == 1)
            {
                for (int j = 0; j < num_vertices; j++)
                {
                    if (weight[i][j] && visited[j] == 0)
                    {
                        if (weight[i][j] < min_weight)
                        {
                            min_weight = weight[i][j];
                            start = i;
                            end = j;
                        }
                    }
                }
            }
        }

        visited[end] = 1;
        mst.push_back(a[end]);
        cout << "Edge: " << a[start] << " - " << a[end] << " Weight: " << min_weight << endl;
    }
}

main()
{
    int n;
    cout<<"Enter number of nodes: ";
    cin>>n
    for (int i = 0; i < n; i++)
    {
        a.push_back(i + 1);
    }
    
    weight = {{0, 4, 14, 18, 0, 5, 0, 0},
              {4, 0, 5, 0, 2, 0, 0, 0},
              {14, 5, 0, 6, 0, 0, 7, 0},
              {18, 0, 6, 0, 0, 0, 0, 1},
              {0, 2, 0, 0, 0, 12, 0, 6},
              {5, 0, 0, 0, 12, 0, 0, 0},
              {0, 0, 7, 0, 0, 0, 0, 8},
              {0, 0, 0, 1, 6, 0, 8, 0}};
    visited = {0, 0, 0, 0, 0, 0, 0, 0};
    prims(0);
}