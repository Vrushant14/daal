#include <bits/stdc++.h>
using namespace std;
vector<int> v;

int main()
{
    while(true){
        int n;
        cout<<"Enter a number: (-1 to stop)";
        cin >> n;
        if(n == -1){
            break;
        }
        v.push_back(n);
    }

    int x;
    cout<<"Enter the number to search: ";
    cin >> x;
    for(int i=0;i<v.size();i++){
        if(v[i] == x){
            cout<<"Found at index "<<i<<endl;
            return 0;
        }
    }
    cout<<"Not found"<<endl;
    return 0;
}