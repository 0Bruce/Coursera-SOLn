#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
//#include <pair>
using namespace std;

int med(int a[],int n){
    int d=a[0],b=a[n/2],c=a[n];
    if(b>=min(d,c) && b<=max(d,c))
        return n/2;
    else if(d>=min(b,c) && d<=max(b,c))
        return 0;
    else 
        return n;
}

int par(int a[],int l,int r){
    int k=med(&a[0],r);
    swap(a[0],a[k]);
    int p=a[0];
    int i=l+1;
    for(int j=l+1;j<=r;j++)
        if(a[j]<p){
            swap(a[j],a[i]);
            i++;
        }
    
    swap(a[i-1],a[0]);
    return i;
}


long long sort(int a[],int n){
    if(n<=1) return 0;
    else{
        long long q=n-1;
        int i=par(&a[0],0,n-1);
        q+=sort(&a[0],i-1);
        
        q+=sort(&a[i],n-i);

        return q;
    }
}






int main(){
    int n;
    cin>>n;
    int a[n] ;
    for(int i=0;i<n;i++)
        cin>>a[i];
    
    long long w=0;
    
    w=sort(a,n);
    
    
    cout<<w<<endl;
}