	if (m == 0 && n == 0)
		return cost[0][0];
	if (m == 0 && n != 0)
		return cost[0][n - 1];
	if (m != 0 && n == 0)
		return cost[m - 1][0];
	return min(cost[m - 1][n - 1],
			   min(minCost(cost, m - 1, n),
				   minCost(cost, m, n - 1)));
}
<|endoftext|>