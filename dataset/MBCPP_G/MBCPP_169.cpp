if (n == 0) return 0;
if (n == 1) return 1;
int pell_prev2 = 0;
int pell_prev1 = 1;
int pell_curr;
for (int i = 2; i <= n; ++i) {
    pell_curr = 2 * pell_prev1 + pell_prev2;
    pell_prev2 = pell_prev1;
    pell_prev1 = pell_curr;
}
return pell_curr;
}