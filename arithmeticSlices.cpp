#include<iostream>
using namespace std;
/*
A sequence of number is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.
For example, these are arithmetic sequence:

1, 3, 5, 7, 9
7, 7, 7, 7
3, -1, -5, -9

The following sequence is not arithmetic.

1, 1, 2, 5, 7

The function should return the number of arithmetic slices in the array A. 
*/
int numberOfArithmeticSlices(vector<int>& A) {
    int ret=0,j;
    for(int i=1;i<A.size();i=j){
        for(j=i+1;j<A.size() && A[j-1]-A[j]==A[i-1]-A[i];++j);
        ret+=(j-i)*(j-i-1)/2;
    }
    return ret;
}

int main()
{
    vector<int> a{1,2,3,4,5};
    cout<<numberOfArithmeticSlices(a);
    return 0;
}
