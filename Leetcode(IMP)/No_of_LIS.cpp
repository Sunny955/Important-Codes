#include <bits/stdc++.h>
using namespace std;

int findNumberOfLIS(vector<int>& nums) 
{
    int n=nums.size();
    int *output=new int[n];
    output[0]=1;
    
    for(int i=1;i<n;i++)
    {  output[i]=1;
        for(int j=i-1;j>=0;j--)
        {   
            if(nums[j]>=nums[i])
            {
                continue;
            }
            int ans=output[j]+1;
            if(ans>output[i])
            {
                output[i]=ans;
            }
        }
    }
    int first,second;
    first = second = INT_MIN;
    for (int i = 0; i < n; i++) {
   
        if (output[i] > first) {
            second = first;
            first = output[i];
        }
 
        else if (output[i] > second && output[i] != first)
        {
            second = output[i];
        }
    }
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(output[i]==second)
        {
            count++;
        }
    }

    delete[] output;
    return count;
        
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
    int ans=findNumberOfLIS(v);
    cout<<ans<<endl;
}