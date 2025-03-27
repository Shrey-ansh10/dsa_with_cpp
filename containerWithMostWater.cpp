#include <iostream>
#include <vector>
using namespace std;


int maxArea(vector<int>& height) {
    int maxCap=0;
    int lp=0; // this is left pointer that will keep track of the index of left wall. Start from starting of array.
    int rp=height.size()-1; // this is the right pointer that will keep track of right wall. start from end of array.

    while(lp<rp){
        int cap = (rp-lp) * min(height[lp], height[rp]);
        //if(maxCap<cap)  maxCap = cap;
        maxCap = max(maxCap, cap); //faster than above statement, this is what took the sol from 3ms to 0 ms
        if(height[lp]<height[rp]) lp++;
        else rp--;
    }
    return maxCap;
}

int main() {
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout << maxArea(height) << endl;
}