#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

void swap_a(int *a,int *b)
{
    int temp ;
    temp = *a;
    *a = *b;
    *b = temp;

}
void swap_b(int *a,int *b)
{
    *a = *a^*b;
    *b = *a^*b;
    *a = *a^*b;
}
void randomint(int a[],int _range,int _length)
{
    if(_length<=0) return;
    for(int i = 0; i < _range;++i)
    {
        a[i]=(rand()%_range);
    }
}
int reservoirsampling(int a[],int end)
{
    int i = 1;
    int ans =a[0];
    while(a[i]!=end){
       if(rand()%i==1) ans = a[i];
       i++;
    }
    return ans;

}
void reservoirsamplingk(int a[],int _length,int _k)
{
    if(_k>_length) return;
    for(int i = _k; i<_length; i++){
        int temp = rand()%i;
        if(temp<_k)
        {
            swap_b(&a[i],&a[temp]);
        }
    }
}
int main()
{
    //随机产生了一个长度为1000,范围在10000内的随机数组
    //其中随机抽取了一个数字作为结束符位置为counts，在
    //遍历一遍的清况下已概率为1/counts输出结束符之前的
    //任意一个数字
    //@蓄水池算法:读入一个随机长度为n的数组或者文件，
    //遍历一遍，以n分之1输出某一行或者一个数，具体的实
    //现方法就为以1/i确定是否将当前数（行）作为输出，i
    //为当前循环次数。
    //@蓄水池算法应用2：在一个长度为n（n是提前不知道的）
    //的数组里，以概率为k/n选取k个数。或者说，在一个未
    //知或者很大样本空间内随机选取n个数：
    //具体方法：首先前k个数，在下次循环时，以k/i的概率
    //确定是否与前k个数中的某个数是否与当前数替换
    int ans,counts,end;
    int length = 1000;
    int range = 10000;
    int *a = new int[1001];
    randomint(a,length,range);
    counts = rand()%1000;
    end = a[counts];
    ans = reservoirsampling(a,end);
    cout<<"以概率为"<<counts<<"分之一选取了数字："<<ans<<endl;
    for(int i=0;i<10;i++)
        cout<<a[i]<<endl;
    cout<<"////////////////////////////\n"<<endl;
    reservoirsamplingk(a,length,10);
     for(int i=0;i<10;i++)
        cout<<a[i]<<endl;
    delete [] a;
    return 0;
}
