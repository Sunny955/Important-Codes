#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Edges
{
    public: int source;
            int dest;
            int weight;
};

bool compare(Edges e1,Edges e2)
{
    return e1.weight < e2.weight;
}

void krushkal(Edges *input,int n,int E,Edges *MST)
{
    sort(input,input+E,compare);
    int *parent=new int[n];
    for(int i=0;i<n;i++)
    {
        parent[i]=i;
    }
    int count=0;
    int j=0;
    while(count<n-1)
    {
        Edges e=input[j];
        
        int x=parent[e.source];
        int y=parent[e.dest];

        while(x!=parent[x])
        {
            x=parent[x];
        }
        while(y!=parent[y])
        {
            y=parent[y];
        }
        if(x!=y)
        {
            
            parent[x]=y;
            MST[count]=e;
            count++;
        }
        j++;
        
    }
    cout<<endl;
}

int main()
{
    int n,E;
    cin>>n>>E;
   
   Edges *input=new Edges[E];
   Edges *MST= new Edges[n-1];
   for(int i=0;i<E;i++)
   {
       int s,d,w;
       cin>>s>>d>>w;
       input[i].source=s;
       input[i].dest=d;
       input[i].weight=w;
   }
   
   krushkal(input,n,E,MST);
   for(int i=0;i<n-1;i++)
   {
       cout<<MST[i].source<<" "<<MST[i].dest<<" "<<MST[i].weight<<endl;
   }
}