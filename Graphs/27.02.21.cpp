#include<bits/stdc++.h>
using namespace std;

int BFS_level(int **input,bool *visited,int N,int sv,int level)
{
    queue<int> Q;
    int p=0;
    visited[sv]=true;
    
    Q.push(sv);
    Q.push(-1);
    int vertex;
    
    while(!Q.empty())
    {	
        if(p<0)
        {
            break;
        }
        
        vertex=Q.front();
    	Q.pop();
        if(vertex<0)
        {
            	level++;
            	Q.pop();
            	Q.push(vertex);
        }
        else
        { 		for(int i=0;i<N;i++)
            	{
                	if(input[vertex][i]==1 && visited[i]==false)
                	{
                    	if(i==N-1)
                    	{   level++;
                            p=-1;
                        	break;
                    	}
                    	else
                    	{	Q.push(i);
                        	visited[i]=true;
                    	}
                	}
            	}
        }
        
    }   
    return level;
    
}

int BFS_level_new(vector<int> input[],bool *visited,int N,int sv,int *level)
{
    queue<int> Q;
    visited[sv]=true;
    level[0]=INT_MAX;
    level[1]=0;
    int flag=0;
    Q.push(sv);
    
    while(!Q.empty())
    {   
        if(flag<0)
        {
            break;
        }
        
        int vertex=Q.front();
        Q.pop();
        
        for(int i=0;i<input[vertex].size();i++)
        {
            if(visited[input[vertex][i]]==false)
            {
                level[input[vertex][i]]=level[vertex]+1;
                
                if(i==N)
                {
                    flag=-1;
                    break;
                }
                visited[input[vertex][i]]=true;
                Q.push(input[vertex][i]);
            }
        }
    }
    return level[N];
}


int main()
{
	//code
    int T;
    cin>>T;
    for(int p=1;p<=T;p++)
    {
        int N,M;
        cin>>N>>M;
        int X,Y;
        // int **input=new int*[N+1];
        // for(int i=0;i<=N;i++)
        // {
        //     input[i]=new int[N+1];
        //     for(int j=0;j<=N;j++)
        //     {
        //         input[i][j]=0;
        //     }
        // }
        // for(int i=0;i<M;i++)
        // {
        //     cin>>X>>Y;
        //     input[X][Y]=1;
        //     input[Y][X]=1;
        // }

        vector<int> input[N+1];
        
        for(int i=0;i<M;i++)
        {
            cin>>X>>Y;
            input[X].push_back(Y);
            input[Y].push_back(X);
        }
        
        bool *visited=new bool[N+1];
        for(int i=0;i<=N;i++)
        {
            visited[i]=false;
        }
        
        // int level=0;
        // int ans=BFS_level(input,visited,N+1,1,level);
        // cout<<ans<<endl;
        visited[0]=true;
        
        int *level=new int[N+1];
        for(int i=0;i<=N;i++)
        {
            level[i]=0;
        }
        int ans=BFS_level_new(input,visited,N,1,level);
        cout<<ans<<endl;
    }  
	return 0;
}
