#include <bits/stdc++.h>
using namespace std;

vector<int> a;
vector<vector<int>> mat;
vector<vector<int>> weight;
vector<int> visited;
vector<int> mst;

struct triplet
{
    int a, b, c;
};

// Helper function for finding the root of a set using path compression
int find(int x, vector<int> &parent)
{
    if(parent[x] == x)
    {
        return x;
    }
    return parent[x] = find(parent[x], parent);
}

// Helper function for union of two sets with rank optimization
void unionSets(int x, int y, vector<int> &parent)
{
    x = find(x, parent);
    y = find(y, parent);

    if (x != y)
    {
        parent[y] = x;
    }
}

void kruskals(int d)
{
    vector<triplet> kw;
    cout << "KRUSKALS" << endl;
    int min_w = 99999;
    int ne = 0;
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a.size(); j++)
        {
            if (weight[i][j])
            {
                ne++;
            }
        }
    }
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = i + 1; j < a.size(); j++)
        {
            if (weight[i][j] || weight[j][i])
            {
                triplet t;
                t.a = a[i];
                t.b = a[j];
                t.c = weight[i][j];
                kw.push_back(t);
            }
        }
    }

    for (int i = 0; i < kw.size() - 1; i++)
    {
        for (int j = 0; j < kw.size() - i - 1; j++)
        {
            if (kw[j].c > kw[j + 1].c)
            {
                triplet t = kw[j];
                kw[j] = kw[j + 1];
                kw[j + 1] = t;
            }
        }
    }
    cout << "The Vertex Edges in Ascending Order is: " << endl;
    for (int i = 0; i < kw.size(); i++)
    {
        cout << "Start: " << kw[i].a << "End: " << kw[i].b << "Weight: " << kw[i].c << endl;
    }

    vector<int> parent(a.size());
    for (int i = 1; i <= a.size(); i++)
    {
        parent[i] = i;
    }

    vector<triplet> mstedges;
    for (int i = 0; i < kw.size(); i++)
    {
        int u = kw[i].a;
        int v = kw[i].b;

        // Check if adding this edge doesn't create a cycle
        if (find(u, parent) != find(v, parent))
        {
            mstedges.push_back(kw[i]);
            unionSets(u, v, parent);
        }
    }
    cout << "\n\nThe MST is: " << endl;
    for (int i = 0; i < mstedges.size(); i++)
    {
        cout << "Edges: " << mstedges[i].a << " - " << mstedges[i].b << " Weight: " << mstedges[i].c << endl;
    }
}

main()
{
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;
    for (int i = 0; i < 8; i++)
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
    kruskals(0);
}