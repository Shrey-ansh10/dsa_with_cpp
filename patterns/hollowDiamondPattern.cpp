#include <bits/stdc++.h>
using namespace std;

int main() {
	int n=4;
	
    // hollow diamond pattern
    
    // top part
    for(int i=0; i<n; i++){
        
        //outer spaces
        for(int j=0; j<n-i-1; j++){
            cout << " ";
        }
        cout<< '*';
        
        //inner spaces
        if(i!=0){
            for(int j=0; j<2*i-1; j++){ //"j<2*i-1" is taken to run the loop ODD Number of times
                cout<< " ";
            }
            cout <<'*';
        }
        cout<<endl;
    }
    
    
    // lower part
    for(int i=0; i<n-1; i++){
        
        //outer spaces
        for(int j=0; j<i+1; j++){
            cout << " ";
        }
        cout<< '*';
        
        //inner spaces
        if(i!=n-2){
            for(int j=0; j<2*(n-i)-5; j++){  //"j<2*(n-i)-5" is taken to run the loop ODD Number of times
                cout<< " ";
            }
            cout<<'*';
        }
        cout<< endl;
    }
}