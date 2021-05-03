#include <bits/stdc++.h>
using namespace std;

void helper(vector<int>& ar,int sum,vector<vector<int>>& ans,vector<int>& p,int index)
{
    if(sum<0 || index==ar.size())
    {
        return;
    }
    
    if(sum==0)
    {   
        ans.push_back(p);
        return;
    }
    
    for(int i=index;i<ar.size();i++)
    {
        p.push_back(ar[i]);
        helper(ar,sum-ar[i],ans,p,i);
        p.pop_back();
    }
}

vector<vector<int> > combinationSum(vector<int>& ar, int sum)
{
    unordered_set<int> s;
    for(int i=0;i<ar.size();i++)
    {
        s.insert(ar[i]);
    }
    ar.clear();
    for(auto i:s)
    {
        ar.push_back(i);
    }
    sort(ar.begin(),ar.end());
    vector<vector<int>> ans;
    if(sum==0 && ar[0]>0)
    {
        ans.empty();
        return ans;
    }
    
    vector<int> p;
    helper(ar,sum,ans,p,0);
    return ans;

}

int main()
{
    int n,a;
    cin>>n;
    vector<int> ar;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        ar.push_back(a);
    }
    int sum;
    cin>>sum;
    vector<vector<int>> ans=combinationSum(ar,sum);    

    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

}
