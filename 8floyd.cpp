// floyd warshall
#include <bits/stdc++.h>
using namespace std;
const int inf = INT_MAX;
void display(vector<vector<int>> d, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (d[i][j] == inf)
            {
                cout << "inf\t";
            }
            else
            {
                cout << d[i][j] << "\t";
            }
        }
        cout << endl;
    }
}
void floyd(vector<vector<int>> d, int n)
{
    for (int curr = 0; curr < n; curr++)
    {

        for (int i = 0; i < n; i++)
        {
            if (i == curr)
                continue;
            for (int j = 0; j < n; j++)
            {
                if (j == curr)
                    continue;

                if (d[i][curr] != inf && d[curr][j] != inf && d[i][j] > d[i][curr] + d[curr][j])
                {
                    d[i][j] = d[i][curr] + d[curr][j];
                }
            }
        }
        cout << "After keeping row " << curr + 1 << " fixed: " << endl;
        display(d, n);
        cout << endl;
    }
}
main()
{
    int n;
    cin >> n;
    vector<vector<int>> d(n, vector<int>(n, inf));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                d[i][j] = 0;
                continue;
            }
            cout << i << "," << j << "?: (-1 for no edge) ";
            int l;
            cin >> l;
            if (l == -1)
            {
                continue;
            }
            d[i][j] = l;
        }
    }

    floyd(d, n);
}