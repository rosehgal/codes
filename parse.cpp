#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <string.h>



using namespace std;


vector<string> split(const char *str, char c = ' ')
{
    vector<string> result;

    do
    {
        const char *begin = str;

        while(*str != c && *str)
            str++;

        result.push_back(string(begin, str));
    } while (0 != *str++);

    return result;
}



vector<string> parse(string str)
{
    int found = str.find("=");
    vector<string> ret;

    string before = str.substr(0,found);
    string after = str.substr(found+1);
    cout<<before<<"\n";
    cout<<after<<"\n";

    size_t first = after.find("(");
    size_t last = after.find(")");
    ret.push_back(before);

    if(first!=string::npos && last!=string::npos)
    {
        string expr = after.substr(first+1);
        expr = expr.substr(0,expr.length()-1);

        //cout<<expr<<endl;

         vector<string> result= split(expr.c_str(),',');
         for(auto s : result)
            ret.push_back(s);
    }

    else
    {
        // cout<<"else";
        char* s = (char*)after.c_str();
        char* p = strtok(s, "+-*/");
        while (p != NULL)
        {
            string s(p);
            p = strtok (NULL, "+-*/");
            cout<<s;
            ret.push_back(s);
        }
    }
    return ret;
}


int main()
{
    string s;
    cin>>s;
    parse(s);
}
