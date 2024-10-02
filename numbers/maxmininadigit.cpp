#include<bits/stdc++.h>
using namespace std;

void MinMax(int num)
{
    int mini=INT_MAX,maxi=INT_MIN;
    while(num>0)
    {
        int d = num%10;
        mini = min(mini,d);
        maxi=max(maxi,d);
        num=num/10;
    }
    
    cout<<"The minimum number is: "<<mini<<"\n"
        <<"The maximum number is: "<<maxi;
}

int main()
{
    int n = 4726;
    MinMax(n);
    return 0;
}
