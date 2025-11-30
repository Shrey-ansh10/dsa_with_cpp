// LC 3761 : Min Absolute Distance Between Mirror Pairs

#include<iostream>
#include<vector>
using namespace std;

int reverse(int n) {
    // std::string s = std::to_string(n);
    // std::reverse(s.begin(), s.end());    
    // int result = std::stoi(s);
    // return result;

    long long reversed_num = 0;
        while (n > 0) {
        reversed_num = reversed_num * 10 + n % 10;
        n /= 10;
    }
    return (int)reversed_num;
}

int minMirrorPairDistance(vector<int>& nums) { // TC: 0(N) ; SC: O(N)

    unordered_map<int, int> m;
    int minDist = INT_MAX; 

    // traverse throught the array
    for(int i=0; i<nums.size(); i++){
        int rev = reverse(nums[i]); // get the reverse of this num
        
        // find the num in the hashmap
        if(m.find(nums[i]) != m.end()){
            //if found
            int dist = abs(i-m[nums[i]]);
            minDist = min(dist, minDist);
        }else{
            // if not found
            m[rev] = i; // append this number to the map with the, key:nums[i], value:i 
        }
    }

    if(minDist == INT_MAX) return -1; // if minDist is still INT_MAX means no mirror found - so return -1
    else return minDist;
}