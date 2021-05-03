#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int findMin(int *bestPath,int n,bool *visited)
{
    int index=-100;
   for(int i=0;i<n;i++)
   {
       if(bestPath[i]>=0 && visited[i]==false)
       {
           index=i;
           break;
       }
   }
    return index;
}

void shortDistance(int **input,int **Tolls,int *bestPath,vector<int> &best,bool *visited,int n,int t,int nInd)
{
    int vertex=findMin(bestPath,n,visited);
    visited[vertex]=true;
    if(vertex<0 || bestPath[n-1]>0)
    {
        return;
    }
    int sum=INT_MAX;
    int index=-100;
    for(int i=0;i<n;i++)
    {
       if(input[vertex][i]>0 && Tolls[vertex][i]>0 && visited[i]==false)
       {
           if(min(sum,input[vertex][i]+Tolls[vertex][i])==input[vertex][i]+Tolls[vertex][i])
           {
               sum=input[vertex][i]+Tolls[vertex][i];
               index=i;
           }
       }
    }
    bestPath[nInd]=index;
    best.push_back(Tolls[vertex][index]);
    shortDistance(input,Tolls,bestPath,best,visited,n,t,++nInd);
}

int main() {
	int n, t;
	cin >> n >> t;
	
    int **input=new int* [n];
    int **Tolls=new int* [n];
    for(int i=0;i<n;i++)
    {
        input[i]=new int[n];
        Tolls[i]=new int[n];
        for(int j=0;j<n;j++)
        {
            input[i][j]=0;
            Tolls[i][j]=0;
        }
    }
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>input[i][j];
            cin>>Tolls[i][j];
        }
    }
    
    int *bestPath=new int[n];
    for(int i=0;i<n;i++)
    {
        bestPath[i]=0;
    }
    
 	vector<int> best;
    best.push_back(0);
    
    bool *visited=new bool[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
    }
    int nextIndex=1;
    shortDistance(input,Tolls,bestPath,best,visited,n,t,nextIndex);
    
    int sum=0;
    for(int i=0;i<best.size();i++)
    {
        sum+=best[i];
    }
    
    cout<<sum<<endl;
    
}