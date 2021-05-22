// Problem
// There are N houses for sale. The i-th house costs Ai dollars to buy. You have a budget of B dollars to spend.

// What is the maximum number of houses you can buy?

// Input
// The first line of the input gives the number of test cases, T. T test cases follow. Each test case begins with a single line containing the two integers N and B. The second line contains N integers. The i-th integer is Ai, the cost of the i-th house.

// Output
// For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the maximum number of houses you can buy.

// Limits
// Time limit: 15 seconds per test set.
// Memory limit: 1GB.
// 1 ≤ T ≤ 100.
// 1 ≤ B ≤ 105.
// 1 ≤ Ai ≤ 1000, for all i.
// Test set 1
// 1 ≤ N ≤ 100.
// Test set 2
// 1 ≤ N ≤ 105.
// Sample

// Input
 	
// Output
 
// 3
// 4 100
// 20 90 40 90
// 4 50
// 30 30 10 10
// 3 300
// 999 999 999

  
// Case #1: 2
// Case #2: 3
// Case #3: 0

  
// In Sample Case #1, you have a budget of 100 dollars. You can buy the 1st and 3rd houses for 20 + 40 = 60 dollars.
// In Sample Case #2, you have a budget of 50 dollars. You can buy the 1st, 3rd and 4th houses for 30 + 10 + 10 = 50 dollars.
// In Sample Case #3, you have a budget of 300 dollars. You cannot buy any houses (so the answer is 0).
// Note: Unlike previous editions, in Kick Start 2020, all test sets are visible verdict test sets, meaning you receive instant feedback upon submission.

#include<stdio.h>
void makeheap(int[],int);
void heapsort(int[],int);

void heapsort(int x[],int n)
{
    int i,s,f,ivalue;
    for(i=n-1;i>0;i--)
    {
        ivalue=x[i];
        x[i]=x[0];
        f=0;
        if(i==1)
        s=-1;
        else
        s=1;
        if(i>2&&x[2]>x[1])
        s=2;
        while(s>=0&&ivalue<x[s])
        {
            x[f]=x[s];
            f=s;
            s=2*f+1;
            if(s+1<=i-1&&x[s]<x[s+1])
            s++;
            if(s>i-1)
            s=-1;
        }
        x[f]=ivalue;
    }
}

void makeheap(int x[],int n)
{
    int i,value,s,f;
    for(i=1;i<n;i++)
    {
        value=x[i];
        s=i;f=(s-1)/2;
        while(s>0&&x[f]<value)
        {
            x[s]=x[f];
            s=f;
            f=(s-1)/2;
        }
        x[s]=value;
    }
}


int main()
{
    int n,t,k,b;
    scanf("%d",&t);
    for(k=1;k<=t;k++)
    {
        scanf("%d %d",&n,&b);
        int a[n],i,sum=0;
        for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        makeheap(a,n);
        heapsort(a,n);   
        int ans=0;
        for(int i=0;i<n;i++)
		{
			if(a[i]<=b)
			{
				ans++;
				b-=a[i];
			}
		}
        printf("Case #%d: %d\n",k,ans);
        
    }
}
