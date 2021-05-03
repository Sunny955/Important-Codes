#include <bits/stdc++.h>
using namespace std;

long countTriplets(vector<long> arr, long r)
{
    if(arr.size()<3)
    {
        return 0;
    }
    
    unordered_map<long,int> map;
    unordered_set<long> se;

    long count=0;
    
    for(int i=0;i<arr.size();i++)
    {
        if(map.find(arr[i])==map.end())
        {
            map[arr[i]]=1;
        }
        else
        {
            map[arr[i]]++;
        }
        se.insert(arr[i]);
    }
 
    
    int first,second;
    for(auto p:se)
    { 
        first=p*r;
        if(map.find(first)!=map.end())
        {
            second=first*r;
            if(map.find(second)!=map.end())
            {
                count+=map[p]*map[first]*map[second];
            }
            else
            {
                second=-1;
                continue;
            }
        }
        else
        {
            first=-1;
            continue;
        }
    }
   return count; 
}


int main()
{
    long n,a,r;
    cin>>n>>r;
    vector<long> arr;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        arr.push_back(a);
    }
    
    cout<<countTriplets(arr,r);
}