#include<bits/stdc++.h>
using namespace std;

vector<int> AvoidFlood(vector<int> &rains)
{
    vector<int> ans(rains.size(),-1);
    set<int> s;
    unordered_map<int,int> map;
    for(int i=0;i<rains.size();i++)
    {
        if(rains[i]==0)
        {
            s.insert(i);
            ans[i]=1;
        }
        else
        {
            if(map.count(rains[i]))
            {
                int lastIndex=map[rains[i]];
                auto zeroIndex=s.upper_bound(lastIndex);
                if(zeroIndex==s.end())
                {
                    ans.empty();
                    return ans;
                }
                ans[*zeroIndex]=rains[i];
                s.erase(zeroIndex);
            }
            map[rains[i]]=i;
            
        }
    }
    return ans;
}

int main()
{
    vector<int> rains;
    int n,a;
    cin>>n;
    for(int i=0;i<n;i++)
    {   
        cin>>a;
        rains.push_back(a);
    }

    vector<int> ans=AvoidFlood(rains);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }

}