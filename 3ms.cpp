#include <bits/stdc++.h>
using namespace std;
vector<int> v;

void merge(int s, int mid, int e)
{
    vector<int> t;
    int i = s, j = mid + 1, k = 0;
    while (i <= mid && j <= e)
    {
        if (v[i] < v[j])
        {
            t.push_back(v[i]);
            i++;
        }
        else
        {
            t.push_back(v[j]);
            j++;
        }
    }

    while (i <= mid)
    {
        t.push_back(v[i]);
        i++;
    }
    while (j <= e)
    {
        t.push_back(v[j]);
        j++;
    }
    int l = t.size();
    for (int i = s; i <= e; i++)
    {
        v[i] = t[k];
        k++;
    }
}

void mergesort(int s, int e)
{
    if (s < e)
    {
        int mid = (s + e) / 2;
        mergesort(s, mid);
        mergesort(mid + 1, e);
        merge(s, mid, e);
        cout << "Merging from " << s << "to" << e << ": ";
        for (int i = s; i <= e; i++)
        {
            cout << v.at(i) << " ";
        }
        cout << endl;
    }
}

int main()
{   
    while (true)
    {
        int n;
        cout << "Enter a number: (-1 to stop)";
        cin >> n;
        if (n == -1)
        {
            break;
        }
        v.push_back(n);
    }

    mergesort(0, v.size() - 1);
}