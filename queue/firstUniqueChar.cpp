// LC


#include<iostream>
#include<unordered_map>
#include<queue>
using namespace std;

// Approach 1 : Using Queue and hashmap
int firstUniqChar(string s) {

        // We will solve this in the following way
        // Hashmap : will be used to store the frequency of each char
        // Queue will be used to store the order in which each unique char was encountered, later when the string is fully traveresed, we will check the char at front of queue and it's frequency 


        // Steps:
        // 1. Traverse through each character in the string
        // 2. Check if the character is in map or not
        //    2.1 If it exist in map -> update it's freq val by 1
        //    2.2 Else add it to map with freq count 1 and also add it's Index to queue
        //  3. No we will keep checking the character at front of the queue, for each char we will also check it's frequency in map.
        //    3.1 If we get a character  with freq 1; that's the answer return it's index
        //    3.2 pop the element from queue and check next element at front

        unordered_map<char, int> m;
        queue<int> q;

        for(int i=0; i<s.length(); i++){
            if(m.find(s[i]) != m.end()){ // exists in map
                m[s[i]]++; // increment the frequency count
                continue;
            }

            m[s[i]] = 1; // add to map
            q.push(i); // only unique elements will be added to the queue
        }

        while(!q.empty()){
            if(m[s[q.front()]] == 1) return q.front();
            else q.pop();
        }

        // this will occur only when queue becomes empty and no elements had frequency 1
        return -1;
    }


    // Approach - 2 : Using Queue and Unordered map/hashmap
    int firstUniqueChar(string s){
        unordered_map<char, int> m;
        queue<int> q;

        for(int i=0; i<s.length(); i++){
            if(m.find(s[i]) == m.end()){ // if char doesn't exist 
                q.push(i); // insert index in the queue
            }
            m[s[i]]++;

            while(!q.empty() && m[s[q.front()]] >1 ){ // when queue is non empty and front element has occured more than once - remove it from the queue
                q.pop();
            }

        }

        if(q.empty()) return -1;
        else return q.front();

    }


    // This question can also be solved using the frequency array of 26 size 
    