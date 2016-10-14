#include <bits/stdc++.h>
using namespace std;


vector<string> tokenize(string str,char delim)
{
	stringstream ss(str);
	string s;
	vector<string> result;
	while(getline(ss,s,delim))
		result.push_back(s);
	return result;
}

int main()
{
	string str="9,3,4,#,#,1,#,#,2,#,6,#,#";
	for(auto s:tokenize(str,','))
		cout<<s<<"\t";
	return 0;
}
