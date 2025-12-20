// You are given three arrays of length n that describe the properties of n coupons: code, businessLine, and isActive. The ith coupon has:

// code[i]: a string representing the coupon identifier.
// businessLine[i]: a string denoting the business category of the coupon.
// isActive[i]: a boolean indicating whether the coupon is currently active.

// A coupon is considered valid if all of the following conditions hold:
// 1. code[i] is non-empty and consists only of alphanumeric characters (a-z, A-Z, 0-9) and underscores (_).
// 2. businessLine[i] is one of the following four categories: "electronics", "grocery", "pharmacy", "restaurant".
// 3. isActive[i] is true.

// Return an array of the codes of all valid coupons, sorted first by their businessLine in the order: "electronics", "grocery", "pharmacy", "restaurant", and then by code in lexicographical (ascending) order within each category.


#include<iostream>
#include<vector>
using namespace std;

// create a set of valid business line to check if the coupon is of valid business line
unordered_map<string, int> um = {
    {"electronics", 1},
    {"grocery", 2}, 
    {"pharmacy", 3}, 
    {"restaurant", 4} };

bool validStr(string& s){ 
    // our condition says the string should only contain alpha numeric character (capital and small) and underscore

    if(s.empty()) return false;

    for(char c : s){
        if( !(  (c >= 'a' && c <= 'z') || // checks alpha numeric 
                (c >= 'A' && c <= 'Z') || // // we can also use the built in function isalnum() for checking alpha-numeric char
                (c >= '0' && c <= '9') ||
                c == '_' )){
                return false;
        }   
    }
    return true;
}

// define comparator function
bool compareCoupons(const pair<string,string>& a, const pair<string,string>& b) {
    string businessA = a.second;
    string businessB = b.second;
    
    // get priorities
    int prioA = um[businessA];
    int prioB = um[businessB];
    
    // compare by priority first
    if (prioA != prioB) {
        return prioA < prioB;  // lower priority comes first
    }
    
    // if same priority, compare codes alphabetically
    return a.first < b.first;
}

vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
    

    vector<pair<string, string>> validCoupons; // stores (couponCode, businessLine)

    int n = code.size();

    for(int i=0; i<n; i++){
        string s = code[i];

        // check for valid string
        if(validStr(s) && isActive[i] && um.find(businessLine[i]) != um.end() ){
            validCoupons.push_back( { s, businessLine[i] } ); // push to answer array 
        }

    } 

    // next step is to sort them as required. 
    sort(validCoupons.begin(), validCoupons.end(), compareCoupons);

    vector<string> ans;
    for(pair<string, string>& p : validCoupons){
        ans.push_back(p.first);
    }

    return ans;
}


int main() {
    // Test Case 1: Basic example
    {
        vector<string> code = {"SAVE10", "DISCOUNT5", "OFFER20", "SALE30"};
        vector<string> businessLine = {"electronics", "grocery", "electronics", "pharmacy"};
        vector<bool> isActive = {true, true, true, true};
        
        vector<string> result = validateCoupons(code, businessLine, isActive);
        cout << "Test 1: ";
        for(string s : result) cout << s << " ";
        cout << endl;
        // Expected: OFFER20, SAVE10, DISCOUNT5, SALE30
        // Sorted: electronics(SAVE10, OFFER20), grocery(DISCOUNT5), pharmacy(SALE30)
    }
    
    // Test Case 2: With invalid coupons
    {
        vector<string> code = {"CODE_123", "INV@LID", "VALID_1", "test-123"};
        vector<string> businessLine = {"electronics", "electronics", "grocery", "restaurant"};
        vector<bool> isActive = {true, true, true, false};
        
        vector<string> result = validateCoupons(code, businessLine, isActive);
        cout << "Test 2: ";
        for(string s : result) cout << s << " ";
        cout << endl;
        // Expected: CODE_123, VALID_1 ( INV@LID invalid chars, test-123 inactive)
    }
    
    // Test Case 3: Empty and special cases
    {
        vector<string> code = {"", "A1_B2", "C3_D4"};
        vector<string> businessLine = {"electronics", "pharmacy", "invalid"};
        vector<bool> isActive = {true, true, true};
        
        vector<string> result = validateCoupons(code, businessLine, isActive);
        cout << "Test 3: ";
        for(string s : result) cout << s << " ";
        cout << endl;
        // Expected: A1_B2 only (empty rejected, invalid businessLine rejected)
    }
    
    // Test Case 4: Sorting test
    {
        vector<string> code = {"ZCOUPON", "ACOUPON", "BCOUPON", "CCOUPON"};
        vector<string> businessLine = {"restaurant", "electronics", "electronics", "grocery"};
        vector<bool> isActive = {true, true, true, true};
        
        vector<string> result = validateCoupons(code, businessLine, isActive);
        cout << "Test 4: ";
        for(string s : result) cout << s << " ";
        cout << endl;
        // Expected: ACOUPON, BCOUPON, CCOUPON, ZCOUPON 
    }
    
    // Test Case 5: Mixed active/inactive
    {
        vector<string> code = {"ACTIVE1", "ACTIVE2", "INACTIVE1"};
        vector<string> businessLine = {"electronics", "grocery", "electronics"};
        vector<bool> isActive = {true, true, false};
        
        vector<string> result = validateCoupons(code, businessLine, isActive);
        cout << "Test 5: ";
        for(string s : result) cout << s << " ";
        cout << endl;
        // Expected: ACTIVE1, ACTIVE2
    }
    
    return 0;
}