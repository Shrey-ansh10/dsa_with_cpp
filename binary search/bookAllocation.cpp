#include <bits/stdc++.h>
using namespace std; 

/* similar to Leetcode 410

Q. Book Allocation Problem
Given an array of books with number of pages in each book at every index. N = number of books = arr.size(), 
-> Allocate the books to M number of students, and find the smallest value of maximum number of pages allocated to a student. M = number of students.
conditions:
    1. All books are alloted to students. No books remain.
    2. Each student gets atleast one book.
    3. Books are alloted in a contiguous manner.

If any such allocation is not possible, return -1.

Example: 
Input: arr[] = [12, 34, 67, 90], M = 2
Output: 113
Explanation: Books can be distributed in following ways:

-> [12] and [34, 67, 90] – The maximum pages assigned to a student is  34 + 67 + 90 = 191.
-> [12, 34] and [67, 90] – The maximum pages assigned to a student is 67 + 90 = 157.
-> [12, 34, 67] and [90] – The maximum pages assigned to a student is 12 + 34 + 67 = 113.
The third combination has the minimum pages assigned to a student which is 113.

Example 2:
Input: arr[] = [15, 17, 20], k = 5
Output: -1
Explanation: Since there are more students than total books, it’s impossible to allocate a book to each student.

Example 3:
Input: arr[] = [22, 23, 67], k = 1
Output: 112
Explanation: Since there is only 1 student, all books are assigned to that student. So, maximum pages assigned to a student is 22 + 23 + 67 = 112.

*/  



bool isValid(vector<int>& arr, int n, int m, int maxPages){
    int stud=1, pages=0;

    for(int i=0; i<n; i++){
        if(arr[i]>maxPages) return false; //first page is itself bigger that mid/maxPages, so we will discard the left part of search space

        // allocate books to students and keep checking the limit, which is = mid/maxPages
        if(pages+arr[i]<= maxPages){  
            pages+=arr[i]; 
        } else{
            stud++;
            pages=arr[i];
        }
    }

    return stud > m ? false : true; // if stud is more than given k(number of students), then return false 
}


int splitArray(vector<int>& nums, int k) {
    if(k>nums.size()) return -1;

    int sum=0;
    for(int i=0; i<nums.size(); i++){
        sum+=nums[i];
    }

    int ans= -1, st=0, end=sum; //search space

    while(st<=end){
        int mid = st + (end-st) / 2 ;

        if(isValid(nums, nums.size(), k, mid)){ 
            ans = mid; // store the current min
            end = mid -1; // look in left half for even smaller min
        } else{ // min bigger than mid, so search in right search space
            st = mid+1;
        }
    }

    return ans;
}



int main(){
    vector<int> arr = {12, 34, 67, 90};
    int k = 2;
    cout << splitArray(arr, k) << endl;

    return 0;
}