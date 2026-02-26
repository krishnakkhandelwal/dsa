// BITPLAY - PLAYING WITH BITS
// #simple-math

// The problem is very simple.

// You are given a even number N and an integer K and you have to find the greatest odd number M less than N such that the sum of digits in binary representation of M is at most K.
// Input

// For each test case, you are given an even number N and an integer K.
// Output

// For each test case, output the integer M if it exists, else print -1.
// Constraints

// 1 ≤ T ≤ 104

// 2 ≤ N ≤ 109

// 0 ≤ K ≤ 30
// Example

#include <bits/stdc++.h>
using namespace std;
void main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        if (k==0){
            cout<<-1<<endl;
            return ;
        }
        n--;
        if(n % 2 == 0)
            n--;
        while(n >= 0){
            int cnt = __builtin_popcount(n);
            if(cnt <= k){
                cout << n << endl;
                break;
            }
            n -= 2;
        }
        if(n < 0)
            cout << -1 << endl;
    }

}