/*
Character recognition is the conversion of images into text. For now we consider each
character in the picture is a N*M matrix with only zeros and ones, and we need to
recognize K characters. You are to write a program to find minimal number of pixels so
that we can recognize each character.
For example, we have only two characters 'T' and 'L', and the matrix size is 3*3, we
can think 'T' and 'L' are
3 3 2
111
010

010
010
*/

#include<bits/stdc++.h>
using namespace std;
//this will generate subsequences of length k and store that in result
void subsequncesOfKLength(vector<string> prefix,vector<string> strings,int k,vector<vector<string>> &result)
{
    if(k<0)
        return;
    if(k==0)
        result.push_back(prefix);
    //using the idea that either the element is selected or not during a subsequnece
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

//check if the given subsequce perfectly identifies the strings
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
    int lower = ceil(log2(strings.size())),upper=strings.size()-1;
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
    int N, M, K,k;
    cin >> N >> M >> K;
    k=K;

    //converting the matrice to binary strings
    while (k--){
        string str;
        for (int i = 0; i<N; i++){
            string tmp;
            cin >> tmp;
            str += tmp;
        }
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
