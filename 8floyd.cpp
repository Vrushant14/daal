#include <bits/stdc++.h>
using namespace std;

void fw(vector<vector<int>> &distance, int n)
{
    for(int current =0; current<n; current++)
    {
        int i,j;
        for(i=0; i<n; i++)
        {
            if(i==current)
            {
                continue;
            }
            for(j=0; j<n; j++)
            {
                if(j==current)
                {
                    continue;
                }
                if(distance[i][j] > distance[i][current]+distance[current][j])
                {
                    distance[i][j] = distance[i][current]+distance[current][j];
                }        
            }
        }
        cout<<endl;
        cout<<"the matrix after fixing node "<<current<<" is : "<<endl;
        for(i=0; i<n; i++)
        {
            if(i==0)
            {
                cout<<"  ";            
            }
            cout<<i+1<<" ";
        }
        cout<<endl;
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                if(j==0)
                {
                    cout<<i+1<<" ";
                }
                if(distance[i][j] == 999999999)
                {
                    cout<<"- ";
                }
                else
                {
                    cout<<distance[i][j]<<" ";
                }
            }
            cout<<endl;
        }
    }   
}

main()
{
    vector<vector<int>> distance;
    int n;
    cout<<"Enter the number of nodes : "<<endl;
    cin>>n;
    distance.resize(n, vector<int>(n));
    for(int i=0; i<n;i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i==j)
            {
                distance[i][j] = 0;
            }
            else
            {
                cout<<endl;
                cout<<"enter 1 if there exists an edge between node "<<i+1<<" and "<<j+1<<" and enter 2 if no edge"<<endl;
                int l;
                cin>>l;
                if(l==1)
                {
                    cout<<"enter weight of edge between node "<<i+1<<" and "<<j+1<<endl;
                    int weight;
                    cin>>weight;
                    distance[i][j] = weight;
                }
                else
                {
                    distance[i][j] = 999999999;

                }        
            }
        }
    }
    fw(distance, n);
}