#include <bits/stdc++.h>
using namespace std;

string solve(int num)
{
    string ans="";
    unordered_map<int,string> map;
    map[0]="Zero";
    map[1]="One";
    map[2]="Two";
    map[3]="Three";
    map[4]="Four";
    map[5]="Five";
    map[6]="Six";
    map[7]="Seven";
    map[8]="Eight";
    map[9]="Nine";
    map[10]="Ten";
    map[11]="Eleven";
    map[12]="Twelve";
    map[13]="Thirteen";
    map[14]="Fourteen";
    map[15]="Fifteen";
    map[16]="Sixteen";
    map[17]="Seventeen";
    map[18]="Eighteen";
    map[19]="Nineteen";
    map[20]="Twenty";
    map[30]="Thirty";
    map[40]="Forty";
    map[50]="Fifty";
    map[60]="Sixty";
    map[70]="Seventy";
    map[80]="Eighty";
    map[90]="Ninty";

    if(num<=20)
    {
        return map[num];
    }
    if(num<100 && num>20)
    {
        if(map.find(num)==map.end())
        {
             int get=num/10;
            get=get*10;
            ans+=map[get];
            get=num%10;
            ans+=" ";
            ans+=map[get];
            return ans;
        }
        else
        {
            return map[num];
        }
       
    }
    if(num<1000)
    {
        string hundered=solve(num/100)+" Hundered";
        string tens=solve(num%100);

        return hundered+" "+tens;
    }
    if(num<1000000)
    {
        string thousand=solve(num/1000)+" Thousand";
        string hundered=solve(num%1000);

        return thousand+" "+hundered;
    }
    if(num<1000000000)
    {
        string million=solve(num/1000000)+" Million";
        string thousand=solve(num%1000000);

        return million+" "+thousand;
    }
    if(num<100000000000000)
    {
        string billion=solve(num/1000000000)+" Billion";
        string million=solve(num%1000000000);

        return billion+" "+million;
    }
}

int main()
{
    int n;
    cin>>n;
    string ans=solve(n);
    cout<<ans<<endl;
}