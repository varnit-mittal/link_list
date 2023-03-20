#include<stdio.h>

void merge(int arr[], int l, int m, int r)
{
    int n1= m-l+1;
    int n2= r-m;
    int l1[n1],l2[n2];
    int i,j;
    for(i=0;i<n1;i++)
        l1[i]=arr[l+i];
    for(j=0;j<n2;j++)
        l2[j]=arr[m+1+j];
    i=0;
    j=0;
    int k=l;
    while(i<n1 && j<n2)
    {
        if(l1[i]<l2[j])
        {
            arr[k]=l1[i];
            i++;
            k++;
        }
        if(l2[j]<l1[i])
        {
            arr[k]=l2[j];
            j++;
            k++;
        }
    }
    while(i<n1)
    {
        arr[k]=l1[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        arr[k]=l2[j];
        j++;
        k++;
    }
}
void MergeSort(int arr[],int l, int r)
{
    if(l<r)
    {
        int m=l+(r-l)/2;
        MergeSort(arr,l,m);
        MergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

int main()
{
    int arr[]={1,2,5,4,8674,764,989948,2123};
    MergeSort(arr,0,sizeof(arr)/sizeof(arr[0])-1);
    for(int i=0;i<8;i++)
    printf("%d ",arr[i]);
}