// Maximim substring with distinct start

#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;


int maxDistinct(string s) {
        unordered_set<char> m;
        for(char c : s){
            m.insert(c);
        }
        return m.size();
    }

int main(){
    cout << maxDistinct("abab") << endl;
    cout << maxDistinct("ababcsd") << endl;
    std::cout << maxDistinct("bacbadmap") << std::endl;
    
    return 0;
}