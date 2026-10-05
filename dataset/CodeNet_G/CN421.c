typedef long long ll;
const int MOD = 1000000007;
ll C3(ll n) {
    if (n < 3) return 0;
    return n * (n - 1) % MOD * (n - 2) / 6 % MOD;
}
ll mod_add(ll a, ll b) {
    return (a + b) % MOD;
}
ll mod_sub(ll a, ll b) {
    return (a + MOD - b) % MOD;
}
ll solve(int W, int H) {
    ll total = 0;
    total = mod_add(total, C3((W + 1LL) * (H + 1LL)));
    ll v_lines = (W + 1LL) * H % MOD * C3(W + 1) % MOD;
    total = mod_sub(total, v_lines);
    ll h_lines = (H + 1LL) * W % MOD * C3(H + 1) % MOD;
    total = mod_sub(total, h_lines);
    ll diag1_lines = 0;
    for (int d = 0; d <= W + H; d++) {
        ll rows = d <= W ? d + 1 : W - (d - H) + 1;
        ll cols = d <= H ? d + 1 : H - (d - W) + 1;
        diag1_lines = mod_add(diag1_lines, C3((ll)rows * cols % MOD));
    }
    total = mod_add(total, diag1_lines);
    ll diag2_lines = 0;
    for (int d = 0; d <= W + H; d++) {
        ll rows = d <= W ? d + 1 : W - (d - H) + 1;
        ll cols = d <= H ? d + 1 : H - (d - W) + 1;
        diag2_lines = mod_sub(diag2_lines, C3((ll)rows * cols % MOD));
    }
    total = mod_add(total, diag2_lines);
    return total;
}