#include <bits/stdc++.h>
using namespace std;

 vector<string> helper(string s)
 {
     vector<string> v;
     if(s.size()<2)
     {
         return {s};
     }
    
     int n=s.size();
     if(s[0]=='0')
     {
         if(s[n-1]=='0')
         {
             return{};
         }
         string ans=s.substr(0,1)+"."+s.substr(1);
         return {ans};
     }
     if(s[n-1]=='0')
     {
         return {s};
     }
     
     for(int i=1;i<n-1;i++)
     {
         v.push_back(s.substr(0,i+1)+"."+s.substr(i+1));
     }
     v.push_back(s);
     return v;

 }
 
 vector<string> ambiguousCoordinates(string S)
 {
     int n=S.size();
     vector<string> ans;
     vector<string> x;
     vector<string> y;

     for(int i=1;i<n-2;i++)
     {
         x.clear();
         y.clear();
         
         x=helper(S.substr(1,i));
         y=helper(S.substr(i+1,n-i-2));
        
         if(x.empty() || y.empty())
            {    continue; }
        

         for(int a=0;a<x.size();a++)
         {
             for(int b=0;b<y.size();b++)
             {
                 ans.push_back("("+x[a]+","+y[b]+")");
             }
         }
     }
     return ans;
 }

 int main()
 {
     vector<string> ans;
     string input="(123)";
     ans=ambiguousCoordinates(input);
     for(int i=0;i<ans.size();i++)
     {
         cout<<ans[i]<<endl;
     }
 }