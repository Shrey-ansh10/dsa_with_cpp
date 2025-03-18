#include <bits/stdc++.h>
using namespace std;

//butterfly pattern

int main() {
	int n=4;
	
    //top part
    for(int i=0; i<n; i++){
        //star
        for(int j=0; j<i+1; j++){
            cout<<"*";
        }
        
        //spaces
        for(int j=0; j<n-i-1; j++){
            cout<< " ";
        } 
        
        //spaces
        for(int j=0; j<n-i-1; j++){
            cout<< " ";
        }
        
        //star
        for(int j=0; j<i+1; j++){
            cout<<"*";
        }
    
        cout<<endl;
    }
    
    
    //lower part
    for(int i=0; i<n; i++){
        //star
        for(int j=0; j<n-i; j++){
            cout<<"*";
        }
        
        //spaces
        for(int j=0; j<i; j++){
            cout<< " ";
        } 
        
        //spaces
        for(int j=0; j<i; j++){
            cout<< " ";
        }
        
        //star
        for(int j=0; j<n-i; j++){
            cout<<"*";
        }
    
        cout<<endl;
    }
}