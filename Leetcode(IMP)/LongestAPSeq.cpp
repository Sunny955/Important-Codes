#include <bits/stdc++.h>
using namespace std;

int LongestArithmeticSeq(vector<int> &v)
{
    unordered_map<int,int> map;
    // sort(v.begin(),v.end());
    for(int i=1;i<v.size();i++)
    {
        int j=0;
        while(j<i)
        {
            if(map.count(v[i]-v[j])>0)
            {
                map[v[i]-v[j]]++;
            }
            else
            {
                map[v[i]-v[j]]=1;
            }
            j++;
        }
    }
    int Max=INT_MIN;
    for(auto x:map)
    {
        Max=max(Max,x.second);
    }
    return Max+1;
}

int main()
{
    vector<int> v;
    int a,n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        v.push_back(a);
    }
    int ans=LongestArithmeticSeq(v);
    cout<<ans<<endl;    
}