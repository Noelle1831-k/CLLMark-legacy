function minCost(cost, m, n) {
    return cost[0][0] + cost[m][n] + cost[0][n] + cost[m][0];
}
