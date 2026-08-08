// Combination
struct Combination{
    vector<vector<ll>>dp;
    Combination(int N,ll mod=998244353):dp(N+1,vector<ll>(N+1)){
        rep(i,N+1)dp[i][0]=1;
        rep(i,N+1)rep(j,i){
            ll val=dp[i-1][j]+dp[i-1][j+1];
            dp[i][j+1]=val<mod?val:val-mod;
        }
    }ll operator()(int n,int r){
        return n<0|r<0?0:dp[n][r];
    }
};