#include <iostream>
#include <vector>
using namespace std;

int max(int a, int b) {
    if (a>b) return a;
    return b;
}

int rec(int i, int j, string x, string y) {
    if(i == x.length() || j == y.length()) return 0;
    
    if(x[i] == y[j]) {
        return 1+rec(i+1, j+1, x, y);
    }
    else return max(rec(i+1, j, x, y), rec(i, j+1, x, y));
}


int lcs(string x, string y) {
    int dp[x.length()+1][y.length()+1];
    //ini
    for(int i = 0; i<x.length()+1; i++) dp[i][0] = 0;
    for(int i = 0; i<y.length()+1; i++) dp[0][i] = 0;
    //
    for(int i = 1; i < x.length()+1; i++) {
        for(int j = 1; j < y.length()+1; j++) {
            if(x[i-1] == y[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[x.length()][y.length()];
}

int main() {
    string s1 = "hello";
    string s2 = "sshjsjaeslslo";
    
    cout<<lcs(s1, s2);
}