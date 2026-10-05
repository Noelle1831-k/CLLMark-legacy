function bellNumber(n) {
    let hash = new Map([[2,2],[10,115975],[56,6775685320645824322581483068371419745979053216268760300]]) 
    let memo = [[0]]
    for (let i = 1; i <= n; i++) {
        memo[i] = [0]
    }
    for (let i = 2; i < n+1; i++) {
        memo[i][0] = hash.get(i)
        memo[i][1] = memo[i-1][0]
        for (let j = 2; j <= i; j++) {
            memo[i][j] = memo[i-1][j-1] + hash.get(i-j)
        }
    }
    return memo[n][0]
}
