#include <bits/stdc++.h>
using namespace std;

int optimal(priority_queue <int, vector<int>, greater<int> > &files)
{
    int temp;
    int result=0;
    while(files.size()>=2)
    {
        temp=0;
        temp += files.top();
        cout<<files.top()<<" + ";
        files.pop();
        temp += files.top();
        cout<<files.top()<<" = ";
        files.pop();
        result+=temp;
        cout<<temp<<endl;
        files.push(temp);
    }
    return result;
}

main(){
    priority_queue <int, vector<int>, greater<int> > files; 
    cout<<"enter the number of files: "<<endl;
    int n;
    cin>>n;
    int x;
    cout<<"enter the files: "<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>x;
        files.push(x);
    }
    int result = optimal(files);
    cout<<"the minimum number of computations needed to reach optimal merge pattern is : "<<result;
}