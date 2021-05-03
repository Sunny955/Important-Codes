#include<iostream>
#include<queue>
using namespace std;

int main()
{
    priority_queue<int> pq;

    pq.push(20);
    pq.push(2);
    pq.push(120);
    pq.push(0);
    pq.push(29);
    pq.push(40);

    cout<<"Size of pq "<<pq.size()<<endl;

    while(!pq.empty())
    {
        cout<<pq.top()<<endl;
        pq.pop();
    }
    return 0;
}