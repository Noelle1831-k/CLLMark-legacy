typedef long long ll;
int N;
ll H;
ll d[100000];
ll h[100000];
int main() {
    scanf("%d %lld", &N, &H);
    for (int i = 0; i < N - 1; ++i) {
        scanf("%lld %lld", &d[i], &h[i]);
    }
    ll currentHealth = H;
    ll useFountainCount = 0;
    for (int i = 0; i < N - 1; ++i) {
        if (currentHealth > d[i]) {
            currentHealth -= d[i];
        } else {
            ll neededFountains = (d[i] - currentHealth + h[i] - 1) / h[i];
            useFountainCount += neededFountains;
            currentHealth += neededFountains * h[i] - d[i];
        }
    }
    printf("%lld\n", useFountainCount);
    return 0;
}