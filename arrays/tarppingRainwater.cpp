// LC-42 : Trapping Rain Water



#include<iostream>
#include<vector>
using namespace std;


// Approach 1 : TC - O(3n) = O(n) | SC - O(2n) -> O(n) 
    int trap(vector<int>& height) {
        int n = height.size();

        int ans=0;
        vector<int> prevG(n,-1);
        vector<int> nextG(n,-1);

        //prev max
        prevG[0] = height[0];
        for(int i=1; i<n; i++){
            if(prevG[i-1] <= height[i]) prevG[i]=height[i];
            else prevG[i] = prevG[i-1]; 
        }

        //next Max
        nextG[n-1] = height[n-1];
        for(int i=n-2; i>=0; i--){
            if(height[i] >= nextG[i+1]) nextG[i]=height[i];
            else nextG[i] = nextG[i+1];
        }

        for(int i=0; i<n; i++){
            ans += min(nextG[i], prevG[i]) - height[i];
        }

        return ans;
    }

// Approach 2 : Two pointer approach
    int trap(vector<int>& height){
        int l=0;
        int r=height.size()-1;
        int leftMax=0, rightMax=0;
        int ans=0;

        while(l<r){
            leftMax = max(leftMax, height[l]);
            rightMax = max(rightMax, height[r]);

            if(leftMax<rightMax){
                ans+= leftMax - height[l];
                l++;
            }else{
                ans += rightMax - height[r];
                r--;
            }
        }   

        return ans;
        
    }

    int main(){
        vector<vector<int>> inputs = {
            {0,1,0,2,1,0,1,3,2,1,2,1},
            {4,2,0,3,2,5},
        };

        for(vector<int> v : inputs){
            cout << trap(v) << endl;
        }

        return 0;
    }