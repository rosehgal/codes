 #include <bits/stdc++.h>
using namespace std;

int processor_required(vector<pair<int,int>> process)
{
    sort(process.begin(),process.end());
    int processor_count=0;
    vector<pair<int,int> > processor;

    processor.push_back(process[0]);
    for(vector<pair<int,int>>::iterator it=process.begin()+1;it<process.end();++it)
    {
        bool replaced = false;
        for(auto &proc : processor)
        {
            if(proc.second <= (*it).first)
            {
                proc = (*it);
                replaced = true;
            }
        }
        if(!replaced)
            processor.push_back((*it));

        if(processor.size()>processor_count)
            processor_count=processor.size();
        //
        // for(auto v : processor)
        //     cout<<v.first<<" "<<v.second<<endl;
        // cout<<"\n";
    }
    return processor_count;
}

int main()
{
    vector<pair<int,int>> process{{1,2},{2,5},{3,5},{1,7},{6,9},{7,9},{2,16}};
    cout<<processor_required(process);
}
