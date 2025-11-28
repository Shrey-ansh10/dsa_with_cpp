// Stock Span Problem
// -> Span for a stock can be calculated as : max num of consecutive previous days where prices <= todays price
// Include today's price in span , therefore min span for every stocak will be 1.

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> stockSpan1(vector<int>& arr){

    int n = arr.size();
    vector<int> ans;

    // Bruteforce approach - O(n^2)
    for(int i=0; i<n; i++){
        int count = 1; 
        for(int j=i; j>=0; j--){
            if(arr[j]>arr[i]){
                break;
            }
            count++;
        }
        ans.push_back(count);
    }
    return ans;
}

vector<int> stockSpan2(vector<int>& arr){
    stack<int> st;
    vector<int> ans;

    for(int i=0; i<arr.size(); i++){

        int span=0;

        while(!st.empty() && arr[st.top()]<=arr[i]){
            st.pop();
        }
        
        if(!st.empty() && arr[st.top()] > arr[i]){
                span = i - st.top();
                ans.push_back(span);
                st.push(i);
        }else if(st.empty()){
            span = i+1;
            ans.push_back(span);
            st.push(i);
        }
    }
    return ans;
}

int main(){

    vector<vector<int>> inputs = {
        {}, 
        {10},
        {10, 40},
        {40, 10}, 
        {100, 80, 60, 70, 60, 75, 85}, 
        {100, 90, 80, 70, 50, 65, 75, 80, 85}   
    };

    for(vector<int> v : inputs){
        vector<int> ans = stockSpan1(v);
        vector<int> ans2 = stockSpan2(v);


        if(ans.size() != ans2.size()){ 
            cout << "some error" << endl;
            break;
        }

        // print ans from brute force method
        cout << "[";
        for(int i=0; i<ans.size(); i++){
            
            cout << ans[i] ;
            
            if(i!= ans.size()-1){
                cout << ", ";
            }
        }
        cout << "]" << endl;
        
        // print ans from stack based method
        cout << "[";
        for(int i=0; i<ans2.size(); i++){
            
            cout << ans2[i] ;
            
            if( i!= ans2.size()-1){
                cout << ", ";
            }
        }
        cout << "]" << endl;
        
        cout << "-----------------------" << endl;
    }

    return 0;
}