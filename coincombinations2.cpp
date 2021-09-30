#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int mod = 1e9+7;
  int n, target;
  cin >> n >> target;
  vector<int> x(n);
  for (int&v : x) cin >> v;
 
  int dp[n+1][target+1] ;
  
  for(int i=1; i<=target ; i++)
  {
    dp[0][i] = 0 ;
  }
  for(int i=0 ; i<=n ; i++)
  {
     dp[i][0] = 1 ;
  }
 
  for (int i = 1; i <= n; i++) 
  {
    for (int j = 1; j <= target; j++) 
    { 
      if(x[i-1]>j)
      {
           dp[i][j] = dp[i-1][j];
      }
      else
      {
          (dp[i][j] = dp[i-1][j] + dp[i][j-x[i-1]]) %= mod;
      }
      
    }
  }
 
  cout << dp[n][target] << endl;
}
