#include <iostream> 
#include <limits.h> 
#include <iostream>
#include <sstream> 
#include<fstream>
#include<vector>
#include<algorithm>
#include<time.h>
#include<sys/time.h>
#include<stack>
#include<string>
#include<windows.h>
#include<stdlib.h>
#include <string.h> 
#include <queue> 
using namespace std; 

//gcc -Wl,--stack,4194304;

//#pragma comment(linker, "/STACK:2000000")

int k=5,t=0,s=0;
int ll=k+1;
bool boo=false;
int m[6],node[6]{0},f[6];
vector <vector <int>> g(ll),grev(ll);
stack <int> st;



void dfs(vector <vector <int>> &g,int i);
  
void dfs_loop(vector <vector <int>> &grev){
    if(boo)
        s=0;
    else
        t=0;
    for(int i=ll-1;i>0;i--){
        if(!node[i]){
            s=i;
            dfs(grev,i);
        }
    }
}

void dfs(vector <vector <int>> &grev,int i){
    node[i]++;
    if(boo)
        m[s]++;
//    cout<<grev[i][0];
    for(auto c:grev[i])
        if(!node[c])
            dfs(grev,c);
    if(!boo){
        t++;
        f[i]=t;
    }
    
    
    //-----------------------------------------------------------------
    
//    st.push(i);
    
    
    
    
}
  
int main() 
{ 
    
    ifstream input;
    input.open("b.txt");
    if(input.fail())
    {
        cout<<"Error opening file\n";
        exit(1);
    }

//    int q,num=0,i=0,j=0;
//    vector< vector<int> > graph(1),g;
    
//    vector<int> edges(0);

    string edges_string;
    
//    for(int i=1;i<ll;i++)
//        g[i].push_back(i);

    while(!input.eof())
    {
//        input>>ignore_vertice;
        getline(input,edges_string);
        stringstream edges_istring(edges_string);
//        edges.clear();
//        while(edges_istring>>temp)
//            edges.push_back(temp);
        string s,h;
        edges_istring>>s;
        edges_istring>>h;
        
        stringstream eek(s);
        stringstream ek(h);
         int x = 0; 
        eek >> x; 
        int y = 0; 
        ek >> y; 
        
//        g[i][j]++;

//        vertices++;
        
        g[x].push_back(y);
        grev[y].push_back(x);
    }
    
//    for(int i=1;i<ll;i++){
//        for(auto c:g[i])
//            cout<<c<<" ";
//        cout<<endl;
//    }
//    cout<<"__________"<<endl;
//    for(int i=1;i<ll;i++){
//        for(auto c:grev[i])
//            cout<<c<<" ";
//        cout<<endl;
//    }
    
   cout<<"__________"<<endl;
    dfs_loop(grev); 
    
    for(int i=1;i<ll;i++)
        grev[i].erase(grev[i].begin(),grev[i].end());
        
//    vector <int> range;
//    for(int i=1;i<ll;i++){
//        grev[]
//    }
        
    
    for(int i=1;i<ll;i++){
        vector <int> v;
//        v.push_back(g[i]);
        for(auto c:g[i])
            v.push_back(c);
        for(auto c:v)
            grev[f[i]].push_back(c);
    }
//    for(int i=1;i<ll;i++){
//        for(auto c:grev[i])
//            cout<<c<<" ";
//        cout<<endl;
//    }
    for(int i=1;i<ll;i++){
        for(int j=0;j<grev[i].size();j++){
            grev[i][j]=f[grev[i][j]];
        }
    }
    
     cout<<"__________"<<endl;
    
//    for(int i=1;i<ll;i++){
//        for(auto c:grev[i])
//            cout<<c<<" ";
//        cout<<endl;
//    }
    
    
    boo=true;
    
//    node[100]={0};
    for(int i=1;i<ll;i++)
        node[i]=0;
    
    dfs_loop(grev);
    
    cout<<"__________"<<endl;
    
    sort(m,m+ll);
    
    for(int i=0;i<5;i++)
        cout<<m[ll-i-1]<<"  ";
  
    return 0; 
}
