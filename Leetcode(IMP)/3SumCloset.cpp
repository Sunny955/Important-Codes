#include <bits/stdc++.h>
using namespace std;

int threeSumClosest(vector<int>& nums, int target)
{
    int ans=INT_MAX;
    int sum=0;
    int solution;

    sort(nums.begin(),nums.end());

    for(int i=0;i<nums.size()-2;i++)
    {
        int j=i+1;
        int k=nums.size()-1;

        while(j<k)
        {
            sum=nums[i]+nums[j]+nums[k];
            if(ans>abs(sum-target))
            {
                ans=abs(sum-target);
                solution=nums[i]+nums[j]+nums[k];
            }

            if(sum-target>0)
            {
                k--;
            }
            else if(sum-target<0)
            {
                j++;
            }
            else
            {
                return target;
            }

        }
    }
    return solution;
}

int main()
{
    
    int n;
    cin>>n;
    vector<int> nums;
    int a;
    for(int i=0;i<n;i++)
    {
       cin>>a;
       nums.push_back(a);
    }
    int target;
    cin>>target;
    int ans=threeSumClosest(nums,target);
    cout<<"Ans is: "<<ans<<endl;
}
