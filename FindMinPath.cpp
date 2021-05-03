#include <bits/stdc++.h>
using namespace std;

int helper(vector<vector<int>>& grid,int sum,int x,int y,int m,int n)
{
    if(x==m-1 && y==n-1)
    {
        return sum;
    }

    int sum1,sum2;
    if(x+1<m && y<n)
    {
        sum+=grid[x+1][y];
        sum1=helper(grid,sum,x+1,y,m,n);
    }
    if(y+1<n && x<m)
    {
        sum+=grid[x][y+1];
        sum2=helper(grid,sum,x,y+1,m,n);
    }

    sum=min(sum1,sum2);
    return sum;
}

int minPathSum(vector<vector<int>>& grid) 
{
    int m=grid.size();
    int n=grid[0].size();
    int ans=helper(grid,grid[0][0],0,0,m,n);    
    return ans;
}

int main()
{
    vector<vector<int>> v;
    int n,m;
    cin>>m>>n;
    int a;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a;
            v[i].push_back(a);
        }
    }
    int ans=minPathSum(v);
    return ans;
}