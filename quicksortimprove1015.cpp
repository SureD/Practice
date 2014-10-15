#include<iostream>
#include<stdlib.h>
#include<sys/time.h>
using namespace std;

void bublesort(int a[],int _low, int _high);
void randomint(int a[],int _range,int _length)
{
    if(_length<=0) return;
    for(int i = 0; i < _range;++i)
    {
        a[i]=(rand()%_range);
    }
}
int qs_improve(int a[],int _low,int _high)
{
//    if(_low>_high) return -1;
    if((_high-_low)<4)
        bublesort(a,_low,_high);
	int first = _low;
	int key =a[_low];
	for(int t = _low;t<(_high+1);t++)
	{
		if(a[t]<key)
		{
			_low++;
			int temp = a[t];
			a[t]=a[_low];
			a[_low] = temp;
		}
	}
	a[first] = a[_low];
	a[_low] = key;
	return _low;
	
}
///////////////////////////
void qci(int a[],int _low, int _high)
{
	if(_low>_high) return;
	int temp;
    temp = qs_improve(a,_low,_high);
	qci(a,_low,temp-1);
	qci(a,temp+1,_high);	
}
void bublesort(int a[],int _low, int _high)
{
    if(_low>_high) return;
    for(int i=_low;i<=_high;i++)
    {
        for(int j = _high;j>i;j--)
        {
            if(a[j]<a[j-1])
            {
                int temp;
                temp = a[j-1];
                a[j-1] = a[j];
                a[j] = temp;
            }
        }
    }
}
void qsibubule(int a[], int _low ,int _high)
{
    if(_low>_high) return;
    int temp;
    temp = qs_improve(a,_low,_high);
	qsibubule(a,_low,temp-1);
	qsibubule(a,temp+1,_high);	 
}
int main()
{
    struct timeval start,end;
    int interval;
    int* a = new int[1000];
    int length = 1000;
    randomint(a,2000,length);
    gettimeofday(&start,NULL);
//	qci(a,0,length);
//  bublesort(a,0,length);
    qsibubule(a,0,length);
    gettimeofday(&end,NULL);
    interval = 1000000*(end.tv_sec-start.tv_sec)+(end.tv_usec-start.tv_usec);
	for(int i=0;i<length;i++)
		cout<<a[i]<<endl;
    cout<<"sort time:"<<interval/1000.0<<"ms"<<endl;
 //   printf("运行时间为 %f/n",interval/1000.0);
 //   delete a;
	return 0;
}
