#include<bits/stdc++.h>
#include<iostream>
using namespace std;



int pickMin(int *weight,bool *visited,int n)
{
    int min=99999999;
    int vertex=-3836;
    for(int i=0;i<n;i++)
    {
        if(weight[i]<min && visited[i]==false)
        {
            min=weight[i];
            vertex=i;
        }
    }
    return vertex;
    
}

void prims(int **edges,bool *visited,int *weight,int *parent,int n,int E,int **mst)
{
    int vertex=pickMin(weight,visited,n);
    if(vertex<0)
    {
        return;
    }
    visited[vertex]=true;
    
    for(int i=0;i<n;i++)
    {
       if(edges[vertex][i]>0 && visited[i]==false)
       {
           if(edges[vertex][i]<weight[i])
           {
               weight[i]=edges[vertex][i];
               parent[i]=vertex;
               mst[vertex][i]=weight[i];
           }
       }
    }
    
    
    prims(edges,visited,weight,parent,n,E,mst);
    cout<<endl;
}

int main()
{
    int n,E;
    cin>>n>>E;
   
  
   int **edges=new int*[n];
    
    for(int i=0;i<n;i++)
    {
        edges[i]=new int[n];
        for(int j=0;j<n;j++)
        {
            edges[i][j]=0;
        }
    }
    
    int **mst=new int*[n];
    
    for(int i=0;i<n;i++)
    {
        mst[i]=new int[n];
        for(int j=0;j<n;j++)
        {
            mst[i][j]=0;
        }
    }
 
   bool *visited=new bool[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
    }
   int *weight=new int[n];
   for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            weight[i]=0;
        }
       else
       {
           weight[i]=273468;
       }
    }
    
   int *parent=new int[n];
   {
        parent[0]=-1;
   }
    
   for(int i=0;i<E;i++)
   {
       int s,d,w;
       cin>>s>>d>>w;
       edges[s][d]=w;
       edges[d][s]=w;
      
   }
   
   prims(edges,visited,weight,parent,n,E,mst);
   
    bool **newVisit=new bool *[n];
    for(int i=0;i<n;i++)
    {
        newVisit[i]=new bool[n];
        for(int j=0;j<n;j++)
        {
            newVisit[i][j]=false;
        }
    }
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(mst[i][j]>0 && newVisit[i][j]==false)
            {
                newVisit[i][j]=true;
                newVisit[j][i]=true;
                if(i<j)
                {
                    cout<<i<<" "<<j<<" "<<mst[i][j]<<endl;
                }
                else
                {
                    cout<<j<<" "<<i<<" "<<mst[i][j]<<endl;
                }
            }
        }
    }
    
    
}