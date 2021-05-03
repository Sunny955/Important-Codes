#include<bits/stdc++.h>
#include<cmath>
using namespace std;

int stringToNumber(char input[])
{
    int len=strlen(input);
    if(len==1)
    {
        return int(input[0])-48;
    }

    return (int(input[0])-48)*pow(10,len-1)+ stringToNumber(input+1);
}

int main()
{
    char input[50];
    cin >> input;
    cout << stringToNumber(input) << endl;
}