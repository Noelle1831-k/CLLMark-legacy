#define MAX_N 100000
int N, L;
int a[MAX_N];
int folded[MAX_N];
int time[MAX_N];
void simulate() {
    int changes;
    do {
        changes = 0;
        for (int i = 0; i < N; i++) {
            if (folded[i]) continue;
            int left = (i > 0 && !folded[i - 1]) ? a[i - 1] : -1;
            int right = (i < N - 1 && !folded[i + 1]) ? a[i + 1] : -1;
            if (a[i] > left && a[i] > right) {
                a[i]++;
                changes++;
                if (a[i] >= L) {
                    folded[i] = 1;
                }
            }
        }
    } while (changes > 0);
}
int main_core() {
    int i;
    for (i = 0; i < N; i++) {
        folded[i] = (a[i] >= L);
    }
    simulate();
    int max_time = 0;
    for (i = 0; i < N; i++) {
        if (a[i] >= L && !time[i]) {
            time[i]++;
            if (time[i] > max_time) {
                max_time = time[i];
            }
        }
    }
    return max_time;
}