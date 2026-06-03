// Combination
struct Combination{
    vector<vector<ll>>dp;
    Combination(int n,ll mod=998244353):dp(n+1,vector<ll>(n+1)){
        rep(i,n+1){
            dp[i][0]=1;
            for(int j=1;j<=i;++j)dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%mod;
        }
    }ll operator()(int n,int r)const{
        if(n<0||r<0)return 0;
        return dp[n][r];
    }
};