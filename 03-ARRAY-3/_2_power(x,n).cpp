// Implement Pow(x,n) | X raised to the power N
// Problem Statement: Given a double x and integer n, calculate x raised to power n. Basically Implement pow(x, n).

//Leetcode:50   link:https://leetcode.com/problems/powx-n/description/


class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long long nn = n;
        if (nn < 0) nn = -1 * nn;
        while (nn) {
            if (nn % 2) {
                ans = ans * x;
                nn = nn - 1;
            } 
            else {
                x = x * x;
                nn = nn / 2;
            }
        }
        if (n < 0) ans = (double)(1.0) / (double)(ans);
        return ans;
    
    }
};


//Bruteforce Approach
// double myPow(double x, int n) {
//       double ans = 1.0;
//       for (int i = 0; i < n; i++) {
//         ans = ans * x;
//       }
//       return ans;
// }