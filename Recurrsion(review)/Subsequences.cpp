#include<bits/stdc++.h>
using namespace std;

int Subsequence(string input,string output[])
{
    if(input.size()==0)
    {
        output[0]="";
        return 1;
    }

    int smallOutput=Subsequence(input.substr(1),output);
    for(int i=0;i<smallOutput;i++)
    {
        output[i+smallOutput]=input[0]+output[i];
    }
    return 2*smallOutput;
}

int main()
{
    string input;
    cin>>input;

    string *output=new string[1000];
    int count=Subsequence(input,output);

    cout<<"Subsequences are:"<<endl;
    for(int i=0;i<count;i++)
    {
        cout<<output[i]<<endl;
    }
    return 0;
}