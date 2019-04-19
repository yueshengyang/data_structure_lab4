#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#define N 100
using namespace std;

int FindPivot(int low,int high)
{
    srand((unsigned)time(NULL));
    return (low+rand()%(high-low+1));
}

int parition(int low,int high,int a[],int pivotindex)
{
    swap(a[pivotindex],a[low]);
    int temp=a[low];
    int i=low,j=high;
    while (i<j)
    {
        while (a[j]>=temp&&i<j)
            j--;
        while (a[i]<=temp&&i<j)
            i++;
        swap(a[i],a[j]);
    }
    swap(a[low],a[i]);
    return i;
}

void QuickSort(int low,int high,int a[])
{
    int k,pivotindex;
    while (low<high)
    {
        pivotindex=FindPivot(low,high);
        k=parition(low,high,a,pivotindex);
        QuickSort(low,k-1,a);
        low=k+1;
    }
}
void CountSort(int A[], int* B, int length, int k)
{
    int *C = new int[k];
    memset(C, 0, sizeof(int) * (k));

    for (int j = 0; j < length; j++)
    {
        C[A[j]] += 1;
    }

    for (int i = 1; i < k; i++)
    {
        C[i]= C[i]+C[i-1];
    }

    for (int j = length - 1; j >= 0; j--)
    {
        B[C[A[j]] - 1] = A[j];
        C[A[j]] = C[A[j]] - 1;
    }
    delete[] C;
}

void BucketSort(int a[],int b[],int n)
{
    int **bucket = new int*[10];
    for( int i=0; i<10; i++)
    {
        bucket[i] = new int[n];
    }
    int len[10];
    for (int i=0;i<10;i++)
        len[i]=0;
    for (int i=0;i<n;i++)
    {
        bucket[a[i]/10000][len[a[i]/10000]]=a[i];
        len[(a[i]/10000)]++;
    }
    for (int i=0;i<10;i++)
    {
        QuickSort(0,len[i]-1,bucket[i]);
    }
    int count=0;
    for (int i=0;i<10;i++)
    {
        for (int j=0;j<len[i];j++)
        {
            b[count++]=bucket[i][j];
        }
    }
    for (int i=0;i<10;i++)
    {
        delete []bucket[i];
    }
    delete bucket;
}

void RadixSort(int a[],int b[],int n,int maxn)
{
    int k,exp=0,m=1,count[10];
    int *bucket=new int[n];
    while (maxn!=0)
    {
        maxn/=10;
        exp++;
    }
    for (int i=0;i<n;i++)
        b[i]=a[i];
    for (int i=0;i<exp;i++)
    {
        for (int j=0;j<10;j++)
            count[j]=0;
        for (int j=0;j<n;j++)
            count[b[j]/m%10]++;
        for (int j=1;j<10;j++)
            count[j]=count[j]+count[j-1];
        for (int j=n-1;j>=0;j--)
        {
            k=b[j]/m%10;
            bucket[count[k]-1]=b[j];
            --count[k];
        }
        for (int j=0;j<n;j++)
        {
            b[j]=bucket[j];
        }
        m*=10;
    }
    delete []bucket;
}

void menu()
{
    cout<<"1.计数排序"<<endl;
    cout<<"2.桶排序"<<endl;
    cout<<"3.基数排序"<<endl;
    cout<<"0.退出"<<endl;
}
int main()
{
    srand((unsigned)time(NULL));
    double t1,t2,time;
    int n,maxn=-9999;
    cout<<"请输入数据量"<<endl;
    cin>>n;
    int *a=new int[n];
    int *b=new int[n];
    int ch;

    while (1)
    {

        for (int i=0;i<n;i++)
        {
            a[i]=rand()/**10+rand()%10*/;
            if (a[i]>maxn)
                maxn=a[i];
        }
        menu();
        cin>>ch;
        if (ch==0)
            break;
        switch (ch)
        {
            case 1:
                t1=clock();
                CountSort(a,b,n,maxn);
                t2=clock();
                break;
            case 2:
                t1=clock();
                BucketSort(a,b,n);
                t2=clock();
                break;
            case 3:
                t1=clock();
                RadixSort(a,b,n,maxn);
                t2=clock();
                break;
        }
        time=(t2-t1)/CLOCKS_PER_SEC;
        cout<<"排序时间为"<<time<<'s'<<endl;
    }
    delete []a;
    delete []b;
    return 0;
}
