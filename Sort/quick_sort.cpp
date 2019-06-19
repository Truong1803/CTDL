#include<iostream>
using namespace std;
 
void swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}
int partition (int arr[], int left, int right)
{
    int p = arr[right];  
    int l = left;
    int r = right - 1;
    while(true){
        while(l <= r && arr[l] < p) l++;
        while(r >= l && arr[r] > p) r--;
        if (l >= r) break;
        swap(arr[l], arr[r]);
        l++;
        r--;
    }
    swap(arr[l], arr[right]);
    return l;
}
void quickSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int pi = partition(arr, left, right);
        quickSort(arr, left, pi - 1);
        quickSort(arr, pi + 1, right);
    }
}
void print(int arr[], int n)
{
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
int main()
{
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    quickSort(arr, 0, n-1);
    print(arr, n);
    delete arr;
    arr=NULL;
    return 0;
}