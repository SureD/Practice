#include<iostream>
#include<stdio.h>
using namespace std;
int test(int k,int m){
    int a=0,len = k*2;
    for(int i=0;i<k;i++){
        a=(a+m-1)%(len-i);
        if(a<k)
            return 0;
    }
    return 1;
}
void joseph(int x[]){
    int m,k;
    for(int i=1;i<15;i++){
        k = i;
        m = k+1;
        while(1){
             if(test(k,m)){
                x[i] = m;
                break;
            } 
            if(test(k,m+1)){
                x[i] = m+1;
                break;
            }
            m+=k+1;
        }
    }
}
int main(){
    int k;
    int x[16];
    joseph(x);
    while(scanf("%d",&k),k){
        printf("%d\n",x[k]);
    }
    return 0;
}

