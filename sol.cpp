int Solution::solve(vector<int> &a) {
    int n=a.size(),sum=0;
    if(n==1) return a[0];
    for(int i=0;i<n;i++){
        sum+=a[i];
    }
    bool dp[n+1][sum/2];
    for(int i=0;i<n+1;i++){
        dp[i][0]=true;
    }
    for(int i=1;i<sum/2+1;i++){
        dp[0][i]=false;
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum/2+1;j++){
            if(a[i-1]<=j){
                dp[i][j]=dp[i-1][j] ||dp[i-1][j-a[i-1]];
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    int i=sum/2;
    for(i=sum/2;i>=0;i--){
        if(dp[n][i]){
            break;
        }
    }
    return sum-2*i;
}
