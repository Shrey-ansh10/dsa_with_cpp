#include <bits/stdc++.h>
using namespace std;

/* 
    Q. Agressive cow problem.
    Given an array with stalls position, tie the cows to the stalls in such a way that the minimum distance is maximized
*/

bool isValid(vector < int > & arr, int m, int minAllowedDist) { // TC: O(n)
    int cows = 1, lastStallPos = arr[0];

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] - lastStallPos >= minAllowedDist) {
            cows++;
            lastStallPos = arr[i];
        }

        if (cows == m) {
            return true;
        }
    }

    return false;

}


int agressiveCows(vector < int > & arr, int m) { // Time Complexity: O(log(range) *n)
    //if(m>arr.size()) return -1;

    sort(arr.begin(), arr.end()); //sorting array

    int st = 1, end = arr[arr.size() - 1] - arr[0]; //as we have sorted the array, we can select range directly, range will always start from 1 and go till the last stall position.
    int ans = -1;

    while (st <= end) { //binary search 
        int mid = st + (end - st) / 2;
        if (isValid(arr, m, mid)) {
            ans = mid;
            st = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    return ans;
}


int main() {
    vector < int > arr = {2, 12, 11, 3, 26, 7};
    int m = 5;
    cout << agressiveCows(arr, m) << endl; // ans=60
}