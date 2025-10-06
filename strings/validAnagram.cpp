#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;


bool isAnagram(string s, string t) {

        if(s.length() != t.length()) return false;

        unordered_map<char, int> freqMap; //map for storing the char and it's freq
        // unordered_map<char, int> T;

        // looping over the string to calculate the char frequency
        for(int i=0; i<s.length(); i++){ 
            if(freqMap.find(s[i]) != freqMap.end()){ //search for char in the map
                freqMap[s[i]]++; //if found, increase the freq
            }else{
                freqMap[s[i]]=1; //if not found, insert the char with freq 1
            }
        }

        // looping over the second string
        for(int i=0; i<t.length(); i++){
            if(freqMap.find(t[i]) != freqMap.end()){
                freqMap[t[i]]--; // 
            }else{
                return false;
            }
        }

        for(auto i=freqMap.begin(); i != freqMap.end(); i++){
            if(i->second !=0) return false;
        }

        // for(auto& pair : freqMap) {
        //     if(pair.second != 0) return false;
        // }

        return true;
    }


    int main(){
        string s = "anagram";
        string t = "nagaram";

        if(isAnagram(s,t)){
            cout<<"Strings are anagram of each other"<<endl;
        }else{
            cout<<"Strings are not anagram of each other"<<endl;
        }

        return 0;
    }