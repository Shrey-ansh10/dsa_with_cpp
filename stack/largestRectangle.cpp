// LC 84 :
// Given an array with the heights of histogram bar's, with constact width of 1 for each bar. 
// Find the area of largest rectangle that can be formed. It can be a single bar or fromed by combining multiple adjacent bars.


#include<iostream>
#include<stack>
#include<vector>
using namespace std;


int largestRectangleArea(vector<int>& heights) {
    
    // Part-1 : for all the elements in the given array - we'll find two things

    // 1. next smaller
    // 2. previous smaller - which we've done in the previous problems
    // just in our case as we want the width which can be found from the index, so we will store the indexes of previousSmaller and nextSmaller in the arrays

    vector<int> prev(heights.size(), 0);
    vector<int> next(heights.size(), 0);
    stack<int> st;

    // finding previous smaller
    for(int x = 0; x<heights.size(); x++){
        while(!st.empty() && heights[st.top()]>=heights[x]){
            st.pop();
        };

        if(st.empty()){
            prev[x] = -1;
        }else{
            prev[x] = st.top();
        }
        st.push(x);
    }

    // empty the stack
    while(!st.empty()){
        st.pop();
    }

    // finding next smaller ->previous greater
    for(int x=heights.size()-1; x>=0 ; x--){
        while(!st.empty() && heights[st.top()]>=heights[x]){
            st.pop();
        }

        if(st.empty()){
            next[x] = -1;
        }else{
            next[x] = st.top();
        }
        st.push(x);
    }
    
    
    // Part 2 : calculate area and update max area for each bar
    int maxArea = 0; //initilizewith zero


    //traverse throught the arrayand for each bar, try to find the rectangle with max area that can be formed including that bar
    for(int i=0; i<heights.size(); i++){
        
        int width = 1;

        if(next[i] == -1 && prev[i] == -1) width=heights.size();
        else if(next[i] == -1 && prev[i] != -1) width = heights.size()-prev[i]-1;
        else width = next[i] - prev[i] - 1;

        int area = heights[i] * width ; //calculating area for each rectangle

        maxArea = max(maxArea, area);

    }

    return maxArea;
}

int main(){



    return 0;
}