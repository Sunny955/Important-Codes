#include<bits/stdc++.h>
#include <unordered_map>
using namespace std;

int lengthOfLongestSubstring(string s) 
    {
        unordered_map<char,int> map;
        int i=0;
        int j;
        int count=0;
        int max_count=-183734;
        int n=s.size();
        while(i<s.size())
        {
            j=i;

            while(map.count(s[j])==0 && j<s.size())
            {
                map[s[j]]=1;
                count++;
                j++;
            }
            
            if(count==n)
            {
                max_count=count;
                break;
            }

            max_count=max(count,max_count);
            map.clear();
            count=0;
            
            i++;
            
        }
        return max_count;
    }

int main()
{
    string s;
    cin>>s;
    int ans=lengthOfLongestSubstring(s);
    cout<<ans<<endl;
    return 0;
}