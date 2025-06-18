#include<iostream>
#include<vector>
#include<cmath> // for square root function
#include<utility>
using namespace std;

// sieve of eratosthenes
int countPrimes(int n) {
        if(n<2) return 0; //
        
        vector<bool> isPrime(n+1, true);
        int counter = 0;

        for(int i=2; i<n; i++){
            if(isPrime[i]){
                counter++;
                for(int j=i*2; j<n; j+=i){
                    isPrime[j]=false;
                }
            }
        }

        return counter;
    }


 //segmented sieve for finding prime in a given range.
int countPrimesInRange(int L, int R){
    int base = sqrt(R);
    int count=0;
    vector<bool> basePrimes(base+1, true);
    vector<int> primes;

    basePrimes[0] = basePrimes[1] = false; // setting 0 and 1 as false because they are 
    for(int i=2; i<=base; i++){
            if(basePrimes[i]){
                primes.push_back(i);
                for(int j=i*2; j<=base; j+=i){
                    basePrimes[j]=false;
                }
            }
    }

    vector<bool> isPrimeSegment(R-L+1, true); 

    for(int p : primes){
        int firstMultiple = max(p*p, ((L+p-1)/p)*p);
        for (int j=firstMultiple; j<=R; j+=p){
            isPrimeSegment[j-L] = false;
        }
    }

    for(bool isP : isPrimeSegment){
        if(isP) count++;
    }

    return count; //return total number of primes in given range
}


int main(){

    int num = 2000;
    cout << "Total Prime Numbers till" << num << "is" << countPrimes(num) << endl;

    cout << countPrimesInRange(25, 75) << endl;
    return 0;
}