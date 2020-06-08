/*
You are given coins of different denominations and a total amount of money. Write a function to compute the number of combinations that make up that amount. You may assume that you have infinite number of each kind of coin.
Input: amount = 5, coins = [1, 2, 5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
Example 2:

Input: amount = 3, coins = [2]
Output: 0
Explanation: the amount of 3 cannot be made up just with coins of 2.
Example 3:

Input: amount = 10, coins = [10]
Output: 1
*/

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        int t[n+1][amount+1];
        memset(t,0,sizeof(t));
        for(int i=0;i<n+1;i++)
            t[i][0]=1;
        for(int i=1;i<n+1;i++){
            for(int j=1;j<amount+1;j++){
                if(coins[i-1]<=j){
                    t[i][j]=t[i][j-coins[i-1]] + t[i-1][j];
                }
                else
                      t[i][j]=t[i-1][j];
            }
        }
        return t[n][amount];
        }
};
