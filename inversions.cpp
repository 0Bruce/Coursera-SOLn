#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
//#include <pair>
using namespace std;

long long inspl(int a[],int n){
    long long i=0,j=0,q=0,k=0;
    int b[n/2],c[n-n/2];
    for(int k=0;k<n/2;k++) b[k]=a[k];
    for(int k=0;k<n-n/2;k++) c[k]=a[k+n/2];

    for ( k=0;k<n;k++) {
        if(c[j]<b[i]){
            a[k]=(c[j]);
            j++;
            q+=n/2-i;
        }
        else{
            a[k]=(b[i]);
            i++;
        }
        if(i>=n/2||j>=n-n/2){
            k++;
            break;
        }
    }
    
    if(i<n/2){
        for(;i<n/2;i++){
            a[k]=b[i];
            k++;
        }
    }
    else if(j<n-n/2)
        for(;j<n-n/2;j++){
            a[k]=c[j];
            k++;
        }
    
    
    
    return q;
}


long long solve(int a[],int n){
    if(n==1) return  0;
    else{
//        int b[n/2],c[n-n/2],d[n];
        long long x=0,y=0,z=0;
        x=solve(&a[0],n/2);
        y=solve(&a[n/2],n-n/2);
        z=inspl(&a[0],n);
        
        return x+y+z;
    }
}






int main(){
    int n=100000;
//    cin>>n;
    int a[n] ;
    for(int i=0;i<n;i++)
    cin>>a[i];
    
    long long w=0;
    
    w=solve(a,n);
    
    
    cout<<w<<endl;
}
