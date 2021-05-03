#include <bits/stdc++.h>
using namespace std;

bool isValid(int i,int j,int n,int m,int dis,vector<vector<int> >& ans,vector<vector<int> >& matrix)
{
    return (i>=0 && i<n && j>=0 && j<m && matrix[i][j]!=0 && dis<ans[i][j]);
}


vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) 
{
    int n=matrix.size();
    int m=matrix[0].size();
    vector<vector<int>> ans(n,vector<int>(m,INT_MAX));
    queue<pair<int,pair<int,int>>> Q;

    for(int i=0;i<n;i++)
    { 
        for(int j=0;j<m;j++)
        {
            if(matrix[i][j]==0)
            {
                Q.push({1,{i,j}});
                ans[i][j]=0;
            }
        }
    }
    pair<int,pair<int,int>> p;
    
    while(!Q.empty())
    {
        p=Q.front();
        int dis=p.first;
        int x=p.second.first;
        int y=p.second.second;
        Q.pop();
        if(isValid(x,y+1,n,m,dis,ans,matrix))
        {
            ans[x][y+1]=dis;
            Q.push({dis+1,{x,y+1}});
        }
        if(isValid(x,y-1,n,m,dis,ans,matrix))
        {
            ans[x][y-1]=dis;
            Q.push({dis+1,{x,y-1}});
        }
        if(isValid(x+1,y,n,m,dis,ans,matrix))
        {
            ans[x+1][y]=dis;
            Q.push({dis+1,{x+1,y}});
        }
        if(isValid(x-1,y,n,m,dis,ans,matrix))
        {
            ans[x-1][y]=dis;
            Q.push({dis+1,{x-1,y}});
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> matrix;
    int n,m,a;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        vector<int> input;
        for(int j=0;j<m;j++)
        {   cin>>a;
            input.push_back(a);
        }
        matrix.push_back(input);
        input.clear();
    }
    vector<vector<int>> ans=updateMatrix(matrix);
    cout<<"Output Matrix is: "<<endl;
     for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

}