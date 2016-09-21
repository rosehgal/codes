#include <bits/stdc++.h>

using namespace std;

void swap(int &x,int &y)
{
    int temp = x;
    x=y;
    y=temp;
}

int median(int arr[],int start, int end,int pos)
{
    int j = start;
    int k=start;
    int pivot = arr[end];

    while(k++<end)
        if(arr[k]<=pivot){
            swap(arr[j],arr[k]);
            j++;
        }
    swap(arr[j],arr[end]);
    if(j==pos)
        return arr[j];
    else
        if(pos<j)
            return median(arr,start,j-1,pos);
        else
            return median(arr,j+1,end,pos-j-1);
}

int main()
{
    int a[]={3,2,1,7,5,4};
    cout<<median(a,0,5,3);
    return 0;
}
