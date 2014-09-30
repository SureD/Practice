#include <iostream>
#include <stack>
#include <vector>
#include <math.h>
//#define INT_MAX=65535;
using namespace std;
// 单引号与双引号的区别，单引号代表着字符，双引号代表字符串
int atoi_m(const string& _a)
{
    int size = _a.size();
    int i = 0;
    int sigh = 1;
    int result=0;
    while(_a[i]==' ') i++;
    if(_a[i]=='+') i++;
    if(_a[i]=='-')
    {
        sigh=-1;
        i++;
    }
    if(_a[i]>='0'&&_a[i]<='9') result=_a[i++]-'0';
    for(;i<size;++i)
    {
        if(_a[i]<'0'&&_a[i]>'9')
            break;
        else if(_a[i]>='0'&&_a[i]<='9')
        {
            result = result*10+_a[i]-'0';
        }
    }
    return sigh*result;


}
int countformula(const vector<string> &tokens,int n)
{
    stack<int> s;
    int rhs,lfs;
    for(int i=0;i<n;i++)
    {
        if(tokens[i]=="*")
        {
            rhs = s.top();
            s.pop();
            lfs = s.top();
            s.pop();
            s.push(rhs*lfs);
        } else if(tokens[i]=="+")
        {
            rhs = s.top();
            s.pop();
            lfs = s.top();
            s.pop();
            s.push(rhs+lfs);
        } else if(tokens[i]=="-")
        {
            rhs = s.top();
            s.pop();
            lfs = s.top();
            s.pop();
            s.push(lfs-rhs);
        } else if(tokens[i]=="/")
        {
            rhs = s.top();
            s.pop();
            lfs = s.top();
            s.pop();
            s.push(lfs/rhs);
        } else
        {
            s.push(atoi_m(tokens[i]));
        }

    }
    return s.top();
}
void quicksort(int _a[],int _low,int _high)
{
    //单次扫描
    //以第一个元素作为pivot
    //if(_a==NULL) return;
    if(_low>=_high) return;
    int temp;
    int i=_low;
    int j=_low+1;
    int key=_a[_low];
    for(;j<=_high;j++)
    {
        if(_a[j]<=key)
        {
            ++i;
            temp=_a[i];
            _a[i]=_a[j];
            _a[j]=temp;
        }
    }
    _a[_low]=_a[i];
    _a[i]=key;
    quicksort(_a,_low,i-1);
    quicksort(_a,i+1,_high);
}
void quicksort2(int _a[], int _low, int _high)
{
    //从两边向中间扫描
    if (_low>=_high) return;
    int first = _low;
    int last = _high;
    int key = _a[first];
    while(first!=last)
    {
        while(last>first&&_a[last]>=key) last--;
        _a[first]=_a[last];
        while(first<last&&_a[first]<key) first++;
        _a[last]=_a[first];
    }
    _a[first]=key;
    quicksort2(_a,_low,first-1);
    quicksort2(_a,first+1,_high);

}
void swap_m(int *_a,int *_b)
{
    int temp;
    temp = *_a;
    *_a = *_b;
    *_b = temp;
}
// 采用最后一个元素作为pivot元素
void quicksort3(int _a[],int _low,int _high)
{
    if(_low>_high) return;
    int i = _low-1;
    int j = _low;
    int key = _a[_high];
    for(;j<_high;++j)
    {
      if(_a[j]<=key)
      {
          ++i;
          swap_m(_a+i,_a+j);
      }
    }
    ++i;
    swap_m(_a+i,_a+j);
    quicksort3(_a,_low,i-1);
    quicksort3(_a,i+1,_high);

}
int partion4qsort(int _a[],int _low,int _high)
{
    if (_low>_high) return -1;
    int first = _low;
    int last = _high;
    int key = _a[first];
    while(first!=last)
    {
        while(last>first&&_a[last]>=key) last--;
        _a[first]=_a[last];
        while(first<last&&_a[first]<key) first++;
        _a[last]=_a[first];
    }
    _a[first]=key;
    return first;
}
// 快速排序非递归算法采用栈
void quicksort4(int _a[], int _low, int _high)
{
    stack<int> s;
    int mid;
    if(_low<_high)
    {
        mid = partion4qsort(_a,_low,_high);
        if(mid-1>_low)
            {
                s.push(_low);
                s.push(mid-1);
            }
        if(mid+1<_high)
            {
                s.push(mid+1);
                s.push(_high);
            }
    }
    while(!s.empty())
    {
        int q = s.top();
        s.pop();
        int p = s.top();
        s.pop();
        mid = partion4qsort(_a,p,q);
        if(mid-1>p)
        {
            s.push(p);
            s.push(mid-1);
        }
        if(mid+1<q)
        {
            s.push(mid+1);
            s.push(q);
        }


    }
}
//
// Find the Kth permutation
int fac(int n)
{
    int* p = new int[n+1];
    p[0]=1;
    for(int i=1;i<=n;++i)
    {
        p[i] = i*p[i-1];
    }
    int ans = p[n];
    delete [] p;
    return ans;

}
void kpermutation(vector<int> &_a,int k)
{
    vector<int> base = {1,2,3};
    int n = base.size();
    vector<int>::iterator Iter;
    int pos = k;
    int num;
    while(base.size()!=1)
    {   --n;
        int temp = fac(n);
        pos = ceil((double)k/temp);
        pos--;
        k = k % temp;
        _a.push_back(base[pos]);
        base.erase(base.begin()+pos);
    }
    _a.push_back(base[0]);
}
int main()
{
    vector<string> s = {"2", "-1", "+", "3", "*"};
    int a[]={3,4,5,7,2,1,2};
    //
    vector<int> base = {1,2,3,4,5,6,7,8,9};
    vector <int>::iterator Iter;
    vector<int> b;
    kpermutation(b,1);
    Iter = b.begin();
    //base.erase(Iter+1);
    for(;Iter!=b.end();Iter++)
            cout<<" "<<*Iter;
    //cout<<fac(4)<<endl;
    //quicksort4(a,0,6);
    //swap_m(a+1,a+2);
    int i=0;
    while(i<0)
    {
        cout<<base[i++]<<endl;
        //cout<<a[i++]<<endl;
    }
    return 0;
}
