#define MONTHS 12
int calculate_months_to_savings_goal(int L, int M[], int N[]) {
    int savings = 0;
    for (int i = 0; i < MONTHS; i++) {
        savings += (M[i] - N[i]);
        if (savings >= L) {
            return i + 1;
        }
    }
    return -1;
}