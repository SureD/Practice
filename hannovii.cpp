#include<iostream>
#include<stdio.h>
using namespace std;
int DFS(int n, int *A,int *B,int *C){
    if(n==0)
        return true;
    if(B[0]&&n==B[1]){
        return false;
    }
    if(A[0]&&n==A[1]){
        A[1] = A[0]-1;
        return DFS(n-1,++A,C,B);
    }
    if(C[0]&&n==C[1]){
        C[1] = C[0]-1;
        return DFS(n-1,B,A,++C);
    }
    return false;
}
int main()
{
    int A[70],B[70],C[70];
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        cin>>A[0];
        for(int i=1;i<=A[0];i++)
            cin>>A[i];
        cin>>B[0];
        for(int i=1;i<=B[0];i++)
            cin>>B[i];
        cin>>C[0];
        for(int i=1;i<=B[0];i++)
            cin>>C[i];
        if(DFS(n,A,B,C))
            cout<<"true"<<endl;
        else
            cout<<"false"<<endl;

    }
    return 0;
}
