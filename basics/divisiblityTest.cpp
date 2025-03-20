#include <bits/stdc++.h>
using namespace std;


// Q. sum of all numbers from 1 to N, which are divisible by 3

int main() {
    int N;
    std::cin >> N;
    int sum=0;
    
    for(int i=1; i<=N; i++){
        if(i%3==0){
            sum = sum + i;
        }
    }
    cout<< "Sum:"<< sum << endl;
    return 0;
}
