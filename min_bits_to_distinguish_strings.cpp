#include<bits/stdc++.h>
using namespace std;

void subsequncesOfKLength(vector<string> prefix,vector<string> strings,int k,vector<vector<string>> &result)
{
    if(k<0)
        return;
    if(k==0)
        result.push_back(prefix);
    else if(strings[0].size()){
        vector<string> prefix2,strings2;
        for(int i=0;i<prefix.size();++i){
            prefix2.push_back(prefix[i]+strings[i][0]);
            strings2.push_back(strings[i].substr(1));
        }
        subsequncesOfKLength(prefix2,strings2,k-1,result);
        prefix2.clear();
        strings2.clear();
        for(int i=0;i<prefix.size();++i){
            prefix2.push_back(prefix[i]);
            strings2.push_back(strings[i].substr(1));
        }
        subsequncesOfKLength(prefix2,strings2,k,result);
    }
}

bool isValid(vector<string> subseq){
    set<string> existed;
    for(string s:subseq){
        if(existed.find(s)!=existed.end())
            return false;
        else
            existed.insert(s);
    }
    return true;
}

int min_bits_differ(vector<string> strings){
    int lower = ceil(log(strings.size())),upper=strings.size()-1;
    vector<string> prefix(strings.size(),"");
    for(int i=lower;i<=upper;++i){
        vector<vector<string>> subseqs;
        subsequncesOfKLength(prefix,strings,i,subseqs);
        for(auto subseq:subseqs)
            if(isValid(subseq))
                return i;
    }
    return -1;
}



int main(){
    vector<string> strings;
    int K,k;
    cin>>K;
    k=K;
    while (k--){
        string str;
        strings.push_back(str);
    }
    if(K<4)
    {
        cout<<K-1<<endl;
        return 0;
    }
    cout<<min_bits_differ(strings);
    return 0;
}
