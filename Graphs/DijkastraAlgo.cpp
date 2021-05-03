#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int findMin(int *distance,bool *visited,int n)
{
    int min=INT_MAX;
    int index=-1;
    for(int i=0;i<n;i++)
    {
        if(distance[i]<min && visited[i]==false)
        {
            min=distance[i];
            index=i;
        }
    }
    return index;
}

void dijkastra(int **input,int *distance,bool *visited,int n)
{
   int vertex=findMin(distance,visited,n);
   if(vertex<0)
   {
       return;
   }
   visited[vertex]=true;
    
    for(int i=0;i<n;i++)
    {
        if(input[vertex][i]>0 && visited[i]==false)
        {
            if(distance[vertex]+input[vertex][i]<distance[i])
            {
                distance[i]=distance[vertex]+input[vertex][i];
            }
        }
    }
    dijkastra(input,distance,visited,n);
}

int main() {
    // Write your code here
    int n,e;
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
        int s,d,w;
        cin>>s>>d>>w;
        input[s][d]=w;
        input[d][s]=w;
    }
    
    int *distance=new int[n];
    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            distance[i]=0;
        }
        else
        {
            distance[i]=INT_MAX;
        }
    }
    
    bool *visited=new bool[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
    }
    dijkastra(input,distance,visited,n);
    
    for(int i=0;i<n;i++)
    {
        cout<<i<<" "<<distance[i]<<endl;
    }
    
    delete[] visited;
    delete[] distance;
    
    for(int i=0;i<n;i++)
    {
        delete[] input[i];
    }
    delete[] input;
}