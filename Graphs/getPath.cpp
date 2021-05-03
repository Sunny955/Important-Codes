#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void hasPath(int **input,int n,int *visited,int v1,int v2,vector<int> &v)
{
    if(v1==v2)
    {
        return;
    }
    
    visited[v1]=1;
    
    for(int i=0;i<n;i++)
    {
        if(i<=v1 && v1<v2)
        {
            continue;
        }
        if(i>=v1 && v1>v2)
        {
            continue;
        }
        if(input[v1][i]==1 && visited[i]==0)
        {
            v.push_back(i);
            hasPath(input,n,visited,i,v2,v);
        }
    }
    
    
}

vector<int> getPath(int **input,int n,int *visited,int v1,int v2)
{
    visited[v1]=1;
  if(v1==v2){
    vector <int> temp;
    temp.push_back(v1);
    return temp;
  }
    
  vector <int> ans;
  for(int i=0;i<n;i++){

    if(i==v1)
      continue;
    
    if(input[v1][i] && visited[i]==0){
      ans=getPath(input,n,visited,i,v2);
      
      if(!ans.empty()){
          ans.push_back(v1);
          return ans;
      }
    }
  }
  return ans;
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

    int *visited=new int[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=0;
    }
    
    int v1,v2;
    cin>>v1>>v2;
    
    // vector<int> v;
    // hasPath(input,n,visited,v1,v2,v);
    
    // if(v.size()!=0)
    // {
    //     reverse(v.begin(),v.end());
    //     v.push_back(v1);
    //     if(v[0]==v2)
    //     {
    //         for(int i=0;i<v.size();i++)
    //         {
    //             cout<<v[i]<<" ";
    //         }
    //     }
    // }
    // else
    // {
    //     cout<<v1<<" "<<endl;
    // }
    vector<int> getAns;
    getAns=getPath(input,n,visited,v1,v2);
    
    for(int i=0;i<getAns.size();i++)
    {
        cout<<getAns[i]<<" ";
    }
    // Delete all the heap memory
    for(int i=0;i<n;i++)
    {
        delete[] input[i];
    }
    delete[] input;
}



