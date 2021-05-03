#include<iostream>
#include<queue>
using namespace std;

void printDFS(int **input,int n,int sv,bool *visited)
{
    cout<<sv<<endl;
    visited[sv]=1;
    for(int i=0;i<n;i++)
    {
        if(i==sv)
        {
            continue;
        }
        if(input[sv][i]==1 && visited[i]==0)
        {   
            printDFS(input,n,i,visited);
        }
    }
}

void printBFS(int **input,int n,int sv,int *visited)
{
    queue<int> Q;
    visited[sv]=1;
    Q.push(sv);
    while(!Q.empty())
    {
        int v=Q.front();
        Q.pop();
    	cout<<v<<" ";
        for(int i=0;i<n;i++)
        {
            if(input[v][i]==1 && visited[i]==0)
            {
                visited[i]=1;
                Q.push(i);
            }
        }
        
    }
 
    
}

void BFS(int **input,int n)
{
    int *visited=new int[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=0;
    }
    
    for(int i=0;i<n;i++)
    {
        if(visited[i]==0)
        {
            printBFS(input,n,i,visited);
        }
    }
}

int main()
{
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
    printDFS(input,n,0,visited);
    BFS(input,n);

    // Delete all the heap memory
    for(int i=0;i<n;i++)
    {
        delete[] input[i];
    }
    delete[] input;
}


