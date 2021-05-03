#include<bits/stdc++.h>
using namespace std;

int minCount(int n)
{
    if(n<=3)
    {
        return n;
    }

    if(sqrt(n)==float(sqrt(n)))
    {
        return 1;
    }
    int ans=INT_MAX;
    int temp;
    for(int i=1;i<sqrt(n);i++)
    {
        temp=i*i;
        ans=min(ans,1+minCount(n-temp));   
    }
   return ans;
}

int main()
{
    int num;
    cin>>num;

    int ans=minCount(num);
    cout<<ans<<endl;
    return 0;
}