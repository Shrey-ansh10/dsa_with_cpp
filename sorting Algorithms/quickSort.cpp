// Quick Sort Algorithm


#include<iostream>
#include<vector>
using namespace std;

int partAndArrange(vector<int>& arr, int st, int end){
    int idx = st-1, pivot=arr[end];

    for(int j=st; j<end; j++){
        if(arr[j]<=pivot){
            idx++;
            swap(arr[idx], arr[j]);
        }
    }
    idx++;
    swap(arr[idx], arr[end]);
    return idx;
}

void quickSort(vector<int>& arr, int st, int end){
    if(st<end){
        int pivot = partAndArrange(arr, st, end);
        quickSort(arr, st, pivot-1);
        quickSort(arr, pivot+1, end);
    }
}

int main(){
    vector<vector<int>> input = {{3,2,1}, {5,2,6,8,1,3}, {9,10,2,6,1,5}};

    for(vector<int>& i : input){
        quickSort(i, 0, i.size()-1);
        // cout << "1st ";
        for(int j=0; j<i.size(); j++){
            cout << j << " " ;
        }
        cout << endl;
    }
}