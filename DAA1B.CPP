#include<iostream>
using namespace std;
int main(){
    int a[10],ans[10],T,n,j,i,c;
    // Read Array Size
    cin>>n;
    // Read Array Element
    i = 0; 
    while(i < n){
        cin>>a[i];
        i++;
    }
    i = 0; 
    c = 0; 
    j = 0;
    while(i < n){
        if(a[i] == 0)
        c++;
        else
        {
            ans[j] = a[i];
            j++;
        }
        i++;
    }
    i = 0;
    while(i < c){
        ans[j] = 0;
        j++;
    }

    // Display Answer
    i = 0;
    while(i < n){
        cout<<ans[i]<<" ";
        i++;
    }
    
}