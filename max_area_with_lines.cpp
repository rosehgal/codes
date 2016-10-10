#include<bits/stdc++.h>
using namespace std;

int maxArea(vector<int>& height){

	int i=0,j=height.size()-1;

	int area=0;

	while(i<j)
	{
		int h=min(height[i],height[j]);
		area=max(area,(j-i+1)*h);
		while(i<j && height[i]<=h)i++;
		while(i<j && height[j]<=h)j--;
	}
	return area;
}

int main()
{
	vector<int> heights{1,1,2,3,1,8,5};
	cout<<maxArea(heights);
	return 0;
}
