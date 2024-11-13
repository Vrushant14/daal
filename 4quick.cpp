#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int partition(int s,int e){
    int pivot = v[e];
    int i = s-1;
    for(int j=s;j<e;j++){
        if(v[j] < pivot){
            i++;
            int temp = v[i];
            v[i] = v[j];
            v[j] = temp;
        }
    }
    int temp = v[i+1];
    v[i+1] = v[e];
    v[e] = temp;
    return i+1;
}
void quick(int s, int e){
    if(s<e){
        int p = partition(s,e);
        cout<<"After partitioning at "<<p<<": ";
        for(int i=s;i<=e;i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
        quick(s,p-1);
        quick(p+1,e);

    }
}
int main(){
    while(true){
        int n;
        cout<<"Enter a number: (-1 to stop)";
        cin >> n;
        if(n == -1){
            break;
        }
        v.push_back(n);
    }

    quick(0,v.size()-1);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}