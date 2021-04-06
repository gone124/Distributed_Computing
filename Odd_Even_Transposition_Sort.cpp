// code for odd even transposition sort
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
    bool flag=0; // flag to check whether the round number is even or odd
    // if flag==0 round is odd
    // if flag ==1 round is even
    for(int i=0;i<n;i++) // this loop is for n rounds of algorithm
    {
        for(int j=flag;j<n;j=j+2) //
        {
            int mi,ma; // mi is temporary minimum while ma is temporary maximum
            if(j+1<n) // checking last process
            {
                mi=min(a[j],a[j+1]);
                ma=max(a[j],a[j+1]);
                a[j]=mi;
                a[j+1]=ma;
            }
        }
        // loop to show each step of the algorithm
        for(int j=0;j<n;j++)
        cout<<a[j]<<" ";
        cout<<"\n";
        flag=!flag; // changing flag after each round
    }
    return 0;
}
