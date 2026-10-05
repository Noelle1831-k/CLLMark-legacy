int sumOfNaturals = n * (n + 1) / 2;
int squareOfSum = sumOfNaturals * sumOfNaturals;
int sumOfSquares = n * (n + 1) * (2 * n + 1) / 6;
return squareOfSum - sumOfSquares;
}