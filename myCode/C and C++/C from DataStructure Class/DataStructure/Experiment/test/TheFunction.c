#include<stdio.h>
#include<stdlib.h>



int main()
{
    void QuickSort(int *n,int low,int high);

    int Test[]={15,57,18,54,12,98,74};
    int low=0;
    int high=sizeof(Test)/4-1;

     for(int i=low;i<=high;i++)
    {
        printf(" %d ",Test[i]);
    }
    printf("\n");

    QuickSort(Test,low,high);
    for(int i=low;i<=high;i++)
    {
        printf(" %d ",Test[i]);
    }
    return 0;
}


void QuickSort(int *n,int low,int high)
{
    if(low>=high)
    return;

    int key=n[low];
    int L=low;
    int H=high;

    while(L!=H)
    { 
        while(n[H]>=key&&L<H)
        H--;
        n[L]=n[H];
        while(n[L]<=key&&L<H)
        L++;
        n[H]=n[L];

        n[L]=key;
    }

    n[low]=n[L];
    n[L]=key;

    QuickSort(n,low,L-1);
    QuickSort(n,L+1,high);
}