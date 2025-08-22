#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums){

 
    // 1. Bruteforce Approach - TC: O(n^3 * log(uniqueTriplets))
    // int n = nums.size();
    // vector<vector<int>> ans;
    
    // set<vector<int>> uTriplet; //a set to store unique triplets 
    // // here we're using set and not 'unordered_set' because to store an array in an unordered_set and then check if a similar array in already exist, we'll have to write custom hash. 
    
 
    // for(int i=0; i<n; i++){
    //     for(int j=i+1; j<n; j++){
    //         for(int k=j+1; k<n; k++){
    //             int sum = nums[i]+nums[j]+nums[k];
    //             if(sum==0){
    //                 vector<int> triplet = {nums[i],nums[j],nums[k]};
    //                 sort(triplet.begin(), triplet.end()); //sorting the triplet and adding to set, making sure only unique triplets are stored
                    
    //                 //check if the triplet is in the set 
    //                 if(s.find(triplet) == uTriplet.end()){ //if it's not in set
    //                     uTriplet.insert(triplet); //add this unique triplet to set
    //                     ans.push_back(triplet); //then store this to ans
    //                 }
    //             }
                
    //         }
    //     }
    // }
    
    // -------------------------------------------------------------
    
    // 2. Hashing Approach - TC: O( n^2 * log(uniqueTriplets))
    //                       SC: O( uniqueTriplets + n)
    // int n = nums.size();

    // set<vector<int>> uTriplets; //storing unique triplets 


    // // nums[i] + nums[j] + nums[k] = 0
    // // nums[j] + nums[k] = -nums[i] // puter loop will pick this nums[i]
    // // nums[k] = -nums[i] - nums[j] // second(inner) loop will pick this nums[j]
    
    // for(int i=0; i<n;i++){
        
    //     int tar = -nums[i]; // selecting the first number
        
    //     set<int> uNum; //to store the unique nums - remember this will be reset at every iteration of puter loop
        
    //     for(int j=i+1; j<n;j++){ 
            
    //         int c = tar - nums[j]; //calculating the 3rd num req
            
    //         if(uNum.find(c) != uNum.end()){ // searching the 3rd num in the set
    //             vector<int> trip = {nums[i], nums[j], c}; //if it exist -> form a triplet
    //             sort(trip.begin(), trip.end()); // sort the triplet
    //             uTriplets.insert(trip); // store in the set unique triplet
    //         }
        
    //         uNum.insert(nums[j]); // if the 3rd num is not in the set add nums[j] to the unique number set
    //     }
    // }
    
    // vector<vector<int>> ans(uTriplets.begin(), uTriplets.end());
    // return ans;
    
    // _______________________________________________________________
    
    
    // 3. Two Pointer Approach
    // TC: O(n logn + n^2)
    // SC: O(uniqueTriplets)
    
        int n = nums.size();
        
        if(n<2) return {};
        
        if(n==3){
            int sum = nums[0]+nums[1]+nums[2];
            if(sum==0) return {{nums[0], nums[1], nums[2]}};
            else return {};
        }
        
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> ans;
        
        for(int i=0; i<n; i++){
            
            if(i>0 && nums[i]==nums[i-1]) continue;
            
            int st=i+1, end=n-1;
            while(st<end){
                int sum = nums[i] + nums[st] + nums[end];
                
                if(sum > 0){
                    end--;
                } else if(sum < 0){
                    st++;
                } else{
                    ans.push_back({nums[i], nums[st], nums[end]});
                    st++, end--;
                    
                    while(st<end && nums[st]==nums[st-1]){
                        st++;
                    }
                }
            }
            
        }
        return ans;

}



int main() {
    
    vector<vector<int>> testcases = {{-1,0,1,2,-1,4}, {0,1,1}, {0,0,0}};
    
     // print the results
    for(vector<int> m : testcases){
        
        cout << " Triplets for {" ;
        for(int v : m)  cout << v << " " ;
        cout << "} are : ";

        vector<vector<int>> result = threeSum(m);
        
        if(result.empty()){
            cout << "No triplets found" << endl;
            continue;
        } 

        for(vector<int> n: result){
            cout << "{ ";
            for(int s : n){
                cout << s << " " ;
            }
            cout << "} " ;
        }
        cout << endl;
    }

    return 0;
}
