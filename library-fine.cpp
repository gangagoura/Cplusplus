#include<iostream>
using namespace std;
int main()
{
    int actual[3],expected[3],i,j;
    for(i=0;i<3;i++)
    cin>>actual[i];
    for(i=0;i<3;i++)
    cin>>expected[i];
   
    if(actual[2]-expected[2]<0)
        cout<<0;
    else if(actual[2]-expected[2]>0)
        cout<<10000;
    else if(actual[1]-expected[1]<0)
        cout<<0;
    else if(actual[1]-expected[1]>0)
        cout<<500*(actual[1]-expected[1]);
    else if(actual[0]-expected[0]>0)
        cout<<15*(actual[0]-expected[0]);
    else
        cout<<0;
}  
