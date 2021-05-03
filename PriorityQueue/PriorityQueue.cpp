#include<iostream>
#include<vector>
using namespace std;

class PriorityQueue
{
  vector<int> pq;

  public: PriorityQueue()
         {
             
         }

         bool isEmpty()
         {
             return pq.size()==0;
         }

         int getSize()
         {
             return pq.size();
         }

         int getMin()
         {
             if(isEmpty())
             {
                 return 0;
             }
             return pq[0];
         }

         void insert(int element)
         {
             pq.push_back(element);

             int childIndex=pq.size()-1;
             while(childIndex>0)
            {  int parentIndex=(childIndex-1)/2;

                if(pq[parentIndex]>pq[childIndex])
                {         
                     int temp=pq[childIndex];
                    pq[childIndex]=pq[parentIndex];
                    pq[parentIndex]=temp;
                }
                else
                {
                    break;
                }
                childIndex=parentIndex;
            }    
         }

         int removemin()
         {
             int ans=pq[0];
             pq[0]=pq[pq.size()-1];
             pq.pop_back();

             int pIndex=0;
             int LCIndex=2*pIndex+1;
             int RCIndex=2*pIndex+2;       

             while(LCIndex<pq.size())
             {  int minIndex=pIndex;

                 if(pq[LCIndex]<pq[minIndex])
                 {
                     minIndex=LCIndex;
                 }

                 if(RCIndex<pq.size() && pq[RCIndex]<pq[minIndex])
                 {
                    minIndex=RCIndex;
                 }

                 if(minIndex==pIndex)
                 {
                     break;
                 }

                 int temp=pq[minIndex];
                 pq[minIndex]=pq[pIndex];
                 pq[pIndex]=temp;

                 pIndex=minIndex;
                 LCIndex=2*pIndex+1;
                 RCIndex=2*pIndex+2;
             }
             return ans;
         }

};

int main()
{
    PriorityQueue p;
    p.insert(10);
    p.insert(18);
    p.insert(37);
    p.insert(35);
    p.insert(15);
    p.insert(66);
    p.insert(77);

    cout<<"Size of priority queue "<<p.getSize()<<endl;
    cout<<"Removing minimum element "<<p.removemin()<<endl;
    cout<<"Removing minimum element "<<p.removemin()<<endl;
    cout<<"New minimum element is "<<p.getMin()<<endl;
}