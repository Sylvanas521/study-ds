#include <iostream>
#include <algorithm>
#include <ctime>

using namespace std;

// bubble, insert, select, quick, shell, heap
// base number
int BubbleSort(int *a, int length);
int SelectSort(int *a, int length);
int InsertSort(int *a, int length);
void QuickSort(int *a, int length);
void QuickSort_1(int *a, int length);
void QuickSort_2(int *a, int length);
void QuickSort_3(int *a, int length);
int main()
{
    cout << "Hello cpp world!" << endl;

    const int N = 10240;
    int a[N];
    for(int i=0; i<N; i++)
        a[i] = N-i;
    clock_t timestart = clock();


    //BubbleSort(a,N);
    //SelectSort(a,N);
    QuickSort_3(a, N);
    clock_t timeend = clock();
 //   double totalsec = double(timeend - timestart)/CLOCKS_PER_SEC;
  double totalsec = double(timeend - timestart);
    for(int i=0; i<10; i++)
        cout << a[i] << ' ';
    cout << endl;
    cout << totalsec << endl;
    return 0;
}

int BubbleSort(int *a, int length)
{
    bool changed = false;
    int start = 0;
    do{
        changed = false;
        for(int i=start; i<length; i++)
        {
            if(a[i] > a[i+1])
            {
                swap(a[i], a[i+1]);
                changed = true;
            }
        }
        --length;

        for(int i=length-1; i > start; i--)
        {
            if(a[i] < a[i-1])
            {
                swap(a[i], a[i-1]);
                changed = true;
            }
        }
        ++start;

    }while(changed);

    return 0;

}

int InsertSort(int *a, int length)
{
    int tmpele = 0;
    int j = 0;
    for(int i=1; i<length; i++)
    {
        tmpele = a[i];
        for(j = i-1; a[j] > tmpele; j--)
        {
            a[j+1] = a[j];
        }
        a[j+1] = tmpele;
    }
    return 0;
}
int BInsertSort(int *a, int length)
{
    int tmpele = 0;
    int j = 0;

    for(int i=1; i<length; i++)
    {
        tmpele = a[i];

        for(j = i-1; a[j] > tmpele; j--)
        {
            a[j+1] = a[j];
        }
        a[j+1] = tmpele;
    }
    return 0;
}
int ShellSort(int *a, int length)
{

    return 0;
}
int SelectSort(int *a, int length)
{
    int minindex = 0;
    for(int i=0; i<length-1; i++)
    {
        minindex = i;
        for(int j=i+1; j<length; j++)
        {
            if(a[j] < a[minindex])
            {
               minindex = j;
            }
        }
        swap(a[i],a[minindex]);
    }
    return 0;
}


void QuickSort(int *a, int length)
{
    if(length<=1) return;
    if(length==2){
        if(a[1]<a[0]) swap(a[1],a[0]);
        return;
    }

    swap(a[length/2],a[0]);

    int* part = &a[0];
    int* L = a+1;
    int* R = a+length-1;
    while(L<R){
        //while(L<(a+length-1) && *L<=*part) ++L;
        while(L<R && *L<=*part) ++L;
        while(R>a && *R>=*part) --R;
        if(L<R) swap(*L, *R);
    }

    if(*R<*part) swap(*R,*part);
    QuickSort(a,R-a);
    QuickSort(R+1,length-1-(R-a));
}


void QuickSort_1(int *a, int length)
{
    if(length<=1) return;
    if(length==2){
        if(a[1]<a[0]) swap(a[1],a[0]);
        return;
    }

    swap(a[length/2],a[0]);

    int* part = a;
    int* L = a+1;
    int* R = a+length-1;
    while(L<R){
        while(L<R && *R>=*part) --R;
        if(*R<*part && L<R ){
          swap(*R,*part);
          part = R;
          --R;
        }
        while(L<R && *L<=*part) ++L;
        if(*L>*part && L<R  ){
          swap(*L,*part);
          part = L;
          ++L;
        }
    }
    QuickSort_1(a,part-a);
    QuickSort_1(part+1,length-1-(part-a));
}
void QuickSort_2(int *a, int length)
{
    if(length<=1) return;
    if(length==2){
        if(a[1]<a[0]) swap(a[1],a[0]);
        return;
    }

    swap(a[length/2],a[0]);

    int part = a[0];
    int* L = a;
    int* R = a+length-1;
    while(L<R){

        while(L<R && *R>=part) --R;
        *L = *R;

        while(L<R && *L<=part) ++L;
        *R = *L;
    }

    *R = part;

    QuickSort_2(a,R-a);
    QuickSort_2(R+1,length-1-(R-a));
}
void QuickSort_3(int *a, int length)
{
    if(length<=1) return;
    if(length==2){
        if(a[1]<a[0]) swap(a[1],a[0]);
        return;
    }

    swap(a[length/2],a[0]);

    int* L = a;
    int* mi = L;
    int* R= a+length-1;

    for(int *k = L+1; k<=R;k++){
        if(*k < *L){
            swap(*(++mi),*k);
        }
    }
    swap(*L,*mi);

    QuickSort_3(a,mi-a);
    QuickSort_3(mi+1,length-1-(mi-a));
}
