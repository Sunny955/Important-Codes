#include<bits/stdc++.h>
#include<iostream>
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

int main()
{
	int T;
    cin>>T;
    for(int p=1;p<=T;p++)
    {
        int N,M;
        cin>>N>>M;
        int X,Y;
        int **input=new int*[N+1];
        for(int i=0;i<=N;i++)
        {
            input[i]=new int[N+1];
            for(int j=0;j<=N;j++)
            {
                input[i][j]=0;
            }
        }
        for(int i=0;i<M;i++)
        {
            cin>>X>>Y;
            input[X][Y]=1;
            input[Y][X]=1;
        }
       
        
        int *distance=new int[N+1];
    	for(int i=0;i<=N;i++)
    	{
        	if(i==1)
        	{
            	distance[i]=0;
        	}
        	else
        	{
            	distance[i]=INT_MAX;
        	}
    	}
        
    
        bool *visited=new bool[N+1];
        for(int i=0;i<=N;i++)
        {
            visited[i]=false;
        }
        visited[0]=true;
        
        dijkastra(input,distance,visited,N+1);
        
        cout<<distance[N]<<endl;

    }  
	return 0;
}
