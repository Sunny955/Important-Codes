#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int>& nums) 
{
        if(nums.size()<=1)
        {
            return;
        }
    
        bool flag=false;
        for(int i=nums.size()-1;i>=2;i--)
        {
            
            if(nums[i]>nums[i-1])
            {
                int a=nums[i];
                int b=nums[i-1];
                nums[i]=b;
                nums[i-1]=a;
                flag=true;
                break;
            }
        }
        if(flag==false)
        {
            int q=nums[0];
            bool give=false;
            int min_val=INT_MAX;
            int index;
            for(int i=1;i<nums.size();i++)
            {
                if(nums[i]>q && nums[i]<min_val)
                {
                    min_val=nums[i];
                    index=i;
                    give=true;
                }
                
            }
            
            if(give==true)
            {
               nums.erase(nums.begin()+index);
               sort(nums.begin(),nums.end());
                for(int i=nums.size();i>=1;i--)
                {
                    nums[i]=nums[i-1];
                }
                nums[0]=min_val;
                    
            }
            else
            {
                sort(nums.begin(),nums.end());
            }
        }
}