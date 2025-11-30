// Count elements with atleast K greater values

#include<iostream>
#include<vector>
using namespace std;

int countElements(vector<int>& nums, int k) {
    
        if(k==0) return nums.size();
        
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int count=0;
        
        for(int i=0; i<nums.size()-k; i++){
            if(nums[i]<nums[i+1]){
                int greVals = nums.size()-(i+1);
                if(greVals>=k) count++;
                continue;                
            }else{
                for(int j=i+2; j<nums.size(); j++){
                    int greVals =0;
                    if(nums[i]<nums[j]){
                        greVals = nums.size()-j;
                        if(greVals>=k) count++;
                        break; 
                    }
                }   
            }
        }
        return count;
    }


int main() {
    
    vector<vector<int>> v = {
        {1},
        {3,2,1},
        {1,1,2,2},
        {4,5,5,5},
        {8,7,4,6, 8,1,3},
        {40,10, 2,2,5,6,7,7,100, 102},
        // {100, 80, 60, 70, 60, 75, 85, 80, 70}, 
        {100, 90, 80, 70, 50, 65, 75, 80, 85}   };

    // cout << inputs[0].size() << endl;

        // cout << countElements(v[0], 1) << endl;
        // cout << countElements(v[1], 1) << endl;
        // cout << countElements(v[2], 2) << endl;
        // cout << countElements(v[2], 3) << endl;
        // cout << countElements(v[3], 0) << endl;
        
        cout << countElements(v[4], 7) << endl;
        cout << countElements(v[4], 4) << endl;
     
    return 0;
}
