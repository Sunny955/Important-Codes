#include<bits/stdc++.h>
using namespace std;

int keypad(int num,string output[],unordered_map<int,string> map)
{
    if(num==0)
    {
        output[0]="";
        return 1;
    }

    int smallOutput=keypad(num/10,output,map);
    string input[smallOutput];

    for(int i=0;i<smallOutput;i++)
    {
        input[i]=output[i];
    }
    string ans;
    int k=0;
    for(int i=0;i<smallOutput;i++)
    {   
        ans=map[num%10];
        for(int j=0;j<ans.size();j++)
        {   
            output[k+j]=input[i]+ans[j];
        }
        k+=ans.size();
    }

    return smallOutput*ans.size();
}

int main()
{
    int num;
    cin>>num;

    string *output=new string[10000];
     unordered_map<int,string> map;
    map[2]="abc";
    map[3]="def";
    map[4]="ghi";
    map[5]="jkl";
    map[6]="mno";
    map[7]="pqrs";
    map[8]="tuv";
    map[9]="wxyz";
    int count=keypad(num,output,map);

    for(int i=0;i<count;i++)
    {
        cout<<output[i]<<endl;
    }
    return 0;
}