#include <bits/stdc++.h>
using namespace std;
int Binary_Search(int n,vector<int> arr,int left,int right){
    int mid=(left+right)/2;
    if(arr[mid]==n){
        return mid;
    }
    else if(arr[mid]>n){
        return Binary_Search(n,arr,left,mid-1);
    }
    else{
        return Binary_Search(n,arr,mid+1,right);
   }
    
}
int main()
{
    vector<int> arr;
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        arr.push_back(x);
    }
    sort(arr.begin(),arr.end());
    int index=Binary_Search(3,arr,0,arr.size()-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<index<<endl;
    return 0;
}