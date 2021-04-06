// code for median algorithm
#include<bits/stdc++.h> // header file which includes all other header files
using namespace std;
int main()
{
    int n;
    cout<<"enter length of array\n";
    cin>>n;
    int a[n];
    cout<<"enter numbers in array\n";
    for(int i=0;i<n;i++)
    cin>>a[i];
    if(n==1)    // when n==1 algorithm will not work as n-1==0
    {
        cout<<a[0]<<"\n";
        return 0;
    }
    int flag=1; // initially 1%3=1 therfore flag=1
    for(int i=0;i<n-1;i++) // this loop is for n-1 rounds of algorithm
    {
        for(int j=flag;j<n;j=j+3)
        {
            if(j+1<n && j-1>=0)  // when left and right process both exists
            {
                int p,q,r;
                p=min({a[j-1],a[j],a[j+1]});
                r=max({a[j-1],a[j],a[j+1]});
                q=p^r^a[j-1]^a[j]^a[j+1];
                a[j-1]=p;
                a[j]=q;
                a[j+1]=r;
            }
            else if(j+1==n)  // when  only left process exists
            {
                if(a[j-1]>a[j])
                swap(a[j-1],a[j]);
            }
            else            // when only right process exists
            {
                if(a[j]>a[j+1])
                swap(a[j],a[j+1]);
            }
        }
        // loop to show each step of the algorithm
        for(int j=0;j<n;j++)
        cout<<a[j]<<" ";
        cout<<"\n";
        flag=(flag+1)%3;  // to calculate median after each round
    }
    return 0;
}
