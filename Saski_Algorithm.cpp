// Saski n-1 rounds algorithm
#include<bits/stdc++.h> // header file which includes all other header files
using namespace std;
int main()
{
    int n;
    cout<<"enter length of array\n";
    cin>>n;
    int a[n][2];
    int area[n]; // array to keep track of area
    int unique[n][2]; // array to keep track of unique element initially first and last elements are unique
    cout<<"enter numbers in array\n";
    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            area[i]=-1;  // area for first element is -1 initially
            unique[i][1]=1;
            cin>>a[i][1];
        }
        else if(i==n-1)
        {
            area[i]=0;
            unique[i][0]=1;
            cin>>a[i][0];
        }
        else
        {
            area[i]=0;
            unique[i][0]=unique[i][1]=0;
            cin>>a[i][0];
            a[i][1]=a[i][0]; // creating duplicates of each element other than first and last
        }
    }
    cout<<"\n";
    for(int i=0;i<n-1;i++) // this loop is for n-1 rounds of algorithm
    {
        for(int j=0;j<n-1;j++)
        {
              if(a[j][1]>a[j+1][0])   // at each round we compare a[j][1] with a[j+1][0]
              {
                  swap(a[j][1],a[j+1][0]);
                  if(unique[j][1]==1 && unique[j+1][0]==1)
                  {
                      //if unique element travels from left to right then receiving area decreases by 1
                      // if unique element travels from right to left then sending area increses by 1
                      // here both conditions happen therefore area remains unchanged of a[j+1]
                      continue;
                  }
                  else if(unique[j][1]==1 && unique[j+1][0]==0)
                  {
                        // unique element travels from left to right
                        area[j+1]-=1;
                        swap(unique[j][1],unique[j+1][0]);
                  }
                  else  if(unique[j][1]==0 && unique[j+1][0]==1)
                  {
                      // unique element travels from right to left
                      area[j+1]+=1;
                      swap(unique[j][1],unique[j+1][0]);
                  }
                  else
                  {
                      // when no element is unique
                      continue;
                  }
              }
              else // already sorted
              continue;
        }
        // loop for internal sorting of each node except first and last
        for(int j=1;j<n-1;j++)
        {
              if(a[j][0]>a[j][1])
              {
                  swap(a[j][0],a[j][1]);
                  swap(unique[j][0],unique[j][1]);
              }
        }
        // loop to show each step of algorithm with area of each process
        cout<<a[0][1]<<" ";
        for(int j=1;j<n-1;j++)
        cout<<a[j][0]<<","<<a[j][1]<<" ";
        cout<<a[n-1][0];
        cout<<"\n";
        cout<<area[0]<<" ";
        for(int j=1;j<n-1;j++)
        cout<<area[j]<<"  ";
        cout<<area[n-1]<<"\n";
        cout<<"\n";
    }
    // finally printing sorted array if area is -1 then we select a[i][1] that is right element
    // if area is 0 or 1 we select left element
    cout<<a[0][1]<<" ";
    for(int i=1;i<n-1;i++)
    {
        if(area[i]==-1)
        cout<<a[i][1]<<" ";
        else
        cout<<a[i][0]<<" ";
    }
    cout<<a[n-1][0]<<"\n";
    return 0;
}
