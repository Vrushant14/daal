#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int binarysearch(int l,int r, int x){
    if(l<r){
        int mid = (l+r)/2;
        if(v[mid]==x){
            return mid;
        }
        else if(v[mid]<x){
            binarysearch(l,mid-1,x);
        }
        else{
            binarysearch(mid+1,r,x);
        }
    }
    return -1;
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
    for(int i=0;i<v.size();i++){
        for(int j=i+1;j<v.size();j++){
            if(v[i]>v[j]){
                int temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }
    }

    int x;
    cout<<"Enter the number to search: ";
    cin >> x;
    int pos = binarysearch(0,v.size()-1, x);
    if(pos==-1){
        cout<<"Not found"<<endl;
    }
    else{
        cout<<"Found at index "<<pos<<endl;
    }
    return 0;
}