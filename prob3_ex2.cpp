#include <iostream>
#include <string>

using namespace std;

string longestPalindrome(string s) {
    int n = s.size();
    bool dp[n][n] = {false};
    int start = 0, len = 1;
    
    
    for (int i = 0; i < n; i++) {
        dp[i][i] = true;
    }
    
    
    for (int i = 0; i < n-1; i++) {
        if (s[i] == s[i+1]) {
            dp[i][i+1] = true;
            start = i;
            len = 2;
        }
    }
    
    
    for (int k = 3; k <= n; k++) {
        for (int i = 0; i < n-k+1; i++) {
            int j = i+k-1;
            if (dp[i+1][j-1] && s[i] == s[j]) {
                dp[i][j] = true;
                if (k > len) {
                    start = i;
                    len = k;
                }
            }
        }
    }
    
    return s.substr(start, len);
}

int main() {
    string s = "cbbd";
    cout << longestPalindrome(s) << endl; 
    
   
    
    return 0;
}
