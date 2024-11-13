#include <bits/stdc++.h>
using namespace std;

int mindist(int dist[],bool sptset[],int v){
    int dis = INT_MAX,min_ind;
    for(int i=0;i<v;i++){
        if(sptset[i]==false && dist[i]<=min){
            min = dist[i];
            min_ind = i;
        }
    }
    return min_ind;
}
void dij(vector<vector<int>> g,int src,int v){
    vector<int> dist(v,INT_MAX);
    vector<bool> sptset(v,false);
    dist[src] = 0;
    for(int c = 0; c<v-1;c++){
        int u = mindist(dist,sptset,v);
        sptset[u] = true;
        for(int i=0;i<v;i++){
            if(!sptset[i] && g[u][i] && dist[u]!=INT_MAX && dist[u] + g[u][i] < dist[i]){
                dist[i] = dist[u] + g[u][i];
            }
        }
    }
    for (int i = 0; i < V; i++)
        cout << i << " \t\t " << dist[i] << endl;
}
int main(){
    int n;
    cout<<"Enter number of vertices: ";
    cin>>n;
    vector<vector<int>> graph(n,vector<int>(n,0));
    cout<<"Enter the adjacency matrix: "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<"Enter the value of graph["<<i<<"]["<<j<<"]: ";
            cin>>graph[i][j];
        }
    }

    dij(graph,0,n);
    return 0;
}