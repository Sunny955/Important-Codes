#include<bits/stdc++.h>
using namespace std;

void goBFS(int **input,int n,int sv,bool *visited,vector<int> &v)
{
    queue<int> Q;
    Q.push(sv);
    visited[sv]=1;
    
    while(!Q.empty())
    {
        int vertex=Q.front();
        Q.pop();
        v.push_back(vertex);
        for(int i=0;i<n;i++)
        {
            if(input[vertex][i]==1 && visited[i]==0)
            {
                Q.push(i);
                visited[i]=1;
            }
        }
    }
}

int main() {
    // Write your code here
    int n;
    int e;
    cin>>n>>e;
    int **input=new int*[n];

    for(int i=0;i<n;i++)
    {
        input[i]=new int[n];
        for(int j=0;j<n;j++)
        {
            input[i][j]=0;
        }
    }

    for(int i=0;i<e;i++)
    {
        int f,s;
        cin>>f>>s;
        input[f][s]=1;
        input[s][f]=1;
    }

    bool *visited=new bool[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=0;
    }
   
    vector<int> v;
    vector<vector<int>> ans;
    for(int i=0;i<n;i++)
    {
        if(visited[i]==false)
        {  
            goBFS(input,n,i,visited,v);
            sort(v.begin(),v.end());
            ans.push_back(v);
            v.clear();
        }
    }

    for(int i=0;i<ans.size();i++)
    {
       for(int j=0;j<ans[i].size();j++)
       {
           cout<<ans[i][j]<<" ";
       }
        cout<<endl;
    }

    // Delete all the heap memory
    for(int i=0;i<n;i++)
    {
        delete[] input[i];
    }
    delete[] input;
}
