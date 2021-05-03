#include <bits/stdc++.h>
using namespace std;

int LongestConsecutive(vector<int>& input)
{
    priority_queue<int,vector<int>, greater<int>> pq;
    for(int i=0;i<input.size();i++)
    {
        pq.push(input[i]);
    }
    stack<int> st;
    int len=1;
    int max_len=INT_MIN;
    st.push(pq.top());
    while(!pq.empty())
    {
        int b=pq.top();
        if(b==st.top()+1)
        {
            len++;
    
        }
        else
        {
            if(max_len<len)
            {
                max_len=len;
            }
            len=1;
        }
        st.push(b);
        pq.pop();
    }

    if(max_len<len)
    {
        max_len=len;
    }
    return max_len;
}

int main()
{
    int n,a;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        v.push_back(a);
    }
    int ans=LongestConsecutive(v);
    cout<<ans<<endl;
}