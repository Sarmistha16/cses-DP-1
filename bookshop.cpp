#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int n , x ;
    cin>> n >>x ;
    
    vector<int> price(n), pg(n);
  for (int&v : price) cin >> v;
  for (int&v : pg) cin >> v;
 
 
    int dp[n+1][x+1] ;
    
    for(int i=0 ; i<=x ; i++)
    {
       dp[0][i] = 0 ;
    }
    for(int i=1 ; i<=n ; i++)
    {
      dp[i][0] =0 ;
    }
    for(int i=1 ; i<=n;  i++)
    {
      for(int j=1 ; j<=x ; j++)
      {
         if(price[i-1]>j)
         {
           dp[i][j] = dp[i-1][j] ;
         }
         else
         {
           dp[i][j] = max(dp[i-1][j] , pg[i-1] + dp[i-1][j-price[i-1]]) ;
         }
      }
    }
   
    cout<<dp[n][x] <<endl;
 
    return 0 ;
} 
