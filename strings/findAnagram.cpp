// LC-438 : Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.


#include <bits/stdc++.h>
using namespace std;

#include <vector>
#include <string>
using namespace std;

    bool freqMatch(int f1[], int f2[]) {
        for (int i = 0; i < 26; i++) {
            if (f1[i] != f2[i]) return false;
        }
        return true;
    }
    
    vector<int> findAnagrams(string s, string p) {
        int n = s.size(), m = p.size();
        vector<int> ans;
        if (n < m) return ans; // If s is shorter than p, no anagrams possible
    
        int freqP[26] = {0}; // Frequency of p
        int freqWin[26] = {0}; // Frequency of current window in s
    
        // Calculate frequency of p
        for (char c : p) {
            freqP[c - 'a']++;
        }
    
        // Initialize the first window
        for (int i = 0; i < m; i++) { //m=3 so window size is initilized with 3
            freqWin[s[i] - 'a']++;
        }
    
        // Check the first window
        if (freqMatch(freqP, freqWin)) {
            ans.push_back(0);
        }
    
        // Slide the window
        for (int i = 1; i <= n - m; i++) {
            // Remove the leftmost character (exiting the window)
            freqWin[s[i-1] - 'a']--;
            // Add the new character (entering the window)
            freqWin[s[i + m - 1] - 'a']++;
    
            // Check if the current window is an anagram
            if (freqMatch(freqP, freqWin)) {
                ans.push_back(i);
            }
        }

    return ans;
}


int main() {
    
    string s = "abab";

    string p = "ab";
    vector<int> result = findAnagrams(s, p);
    for (int index : result) {
        cout << index << " ";
    }

    return 0;
}