#include<iostream>
#include<queue>
using namespace std;

// kSorted Array is the array which is sorted in decreasing order and it's each element is at max k-1th postion forward or backward
// for eg. 12 15 6 7 9

void kSortedArray(int input[],int n,int k)
{
   priority_queue<int> pq; // max priority queue
   
   for(int i=0;i<k;i++)
   {
       pq.push(input[i]);
   }
   int j=0;
   for(int i=k;i<n;i++)
   {
       input[j]=pq.top();
       pq.pop();
       pq.push(input[i]);
       j++;
   }

   while(!pq.empty())
   {
       input[j]=pq.top();
       pq.pop();
       j++;
   }

   for(int p=0;p<n;p++)
   {
       cout<<input[p]<<" ";
   }
   cout<<endl;
}


int main()
{
    int input[5]={12,15,6,7,9};
    int k=3;
    kSortedArray(input,5,k);
}