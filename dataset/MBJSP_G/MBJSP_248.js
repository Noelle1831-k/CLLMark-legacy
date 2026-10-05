function harmonicSum(n) {
if (n <= 1) return 0;
return 1 / (n - 1) + harmonicSum(n - 1);
}
