#include <bits/stdc++.h>
using namespace std;

// Pyramid patter for numbers
// int main() {
// 	int n=4;
	
// 	for(int i=0; i<n; i++){ //outer loop
	
// 	    for(int j=0; j<=n-i-1; j++){ //spaces
// 	        cout<< " ";
// 	    }
	    
// 	    for(int j=0; j<i+1; j++){ //nums
// 	        cout<< j+1;
// 	    }
	    
// 	    for(int j=i; j>0; j--){ //num
// 	        cout<< j;
// 	    }
	    
// 	    cout<< endl;
// 	}

// }

//for charaters
int main() {
	int n=4;
	
	for(int i=0; i<n; i++){ //outer loop
	
	    for(int j=0; j<=n-i-1; j++){ //spaces
	        cout<< " ";
	    }
	    
	    for(int j=0; j<i+1; j++){ //nums
	        cout<< char('A'+j);
	    }
	    
	    for(int j=i; j>0; j--){ //num
	        cout<< char('A'+j-1);
	    }
	    
	    cout<< endl;
	}

}