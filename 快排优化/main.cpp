#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
#define N 10000000
int A[N];
 void Swap( int &i,  int &j)
{
    int t;
    t = i;
    i = j;
    j = t;
}
int Partition(int list[], int low, int high)
{
    int pivot;
    srand(time(NULL));
    int r=( rand()%(high-low) + low );
    swap(A[r],A[low]);
    pivot = list[low];
    while (low < high)
    {
        while (low < high && list[high] >= pivot)
        {
             high--;
        }
        if (low != high)
        {
            Swap( list[low],  list[high]);
            low++;
        }
        while (low < high && list[low] <= pivot)
        {
            low++;
        }
        if (low != high)
        {
            Swap( list[low],  list[high]);
            high--;
        }
    }
    return low;
}
 void InsertSort(int list[],int low,int high)
{
    for (int i = low; i < high; i++)
    {
        int t = list[i];
        int j = i;
        while ((j > 0) && (list[j - 1] > t))
        {
            list[j] = list[j - 1];
            --j;
        }
        list[j] = t;
    }
}


void myQuickSort(int list[], int low, int high,int k)
{
    if (low < high)
    {
        if(high-low<k)
        {
            InsertSort(list,low,high);
        }
        else{
            int pivot = Partition(list, low, high);
            myQuickSort(list, low, pivot - 1,k);
            myQuickSort(list, pivot + 1, high,k);
        }
    }
}

void QuickSort(int list[], int low, int high,int k)
{
    if (high <= low)
    {
        return;
    }
    else if (high == low + 1)
    {
        if (list[low] > list[high])
        {
            Swap( list[low],  list[high]);
            return;
        }
    }
    myQuickSort(list, low, high,k);
}



int main()
{
    clock_t t1;
    srand(time(NULL));
    for (int i=0;i<N;i++){

        A[i]=rand();
    }
    cout<<"随机数的数量为"<<N<<endl;
    t1 = clock();
    QuickSort(A, 0, N-1,16);
    t1 = clock() - t1;
    cout <<  " 时间为：" << ((float)t1)/CLOCKS_PER_SEC << " s." << endl;
    return 0;
}
