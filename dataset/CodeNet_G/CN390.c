#define MAX_SAGES 10
int a[MAX_SAGES];
int w[MAX_SAGES];
int n;
int min_frustration = 10000;
void calculate_frustration(int perm[]) {
    int total_frustration = 0;
    for (int i = 0; i < n; i++) {
        int next = (i + 1) % n;
        if (a[perm[i]] == 0 && a[perm[next]] == 1) {
            total_frustration += w[perm[i]];
        }
        if (a[perm[i]] == 1 && a[perm[next]] == 0) {
            total_frustration += w[perm[i]];
        }
    }
    if (total_frustration < min_frustration) {
        min_frustration = total_frustration;
    }
}
void permute(int perm[], int size) {
    if (size == 1) {
        calculate_frustration(perm);
        return;
    }
    for (int i = 0; i < size; i++) {
        permute(perm, size - 1);
        if (size % 2 == 1) {
            int temp = perm[0];
            perm[0] = perm[size - 1];
            perm[size - 1] = temp;
        } else {
            int temp = perm[i];
            perm[i] = perm[size - 1];
            perm[size - 1] = temp;
        }
    }
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &w[i]);
    }
    int perm[MAX_SAGES];
    for (int i = 0; i < n; i++) {
        perm[i] = i;
    }
    permute(perm, n);
    printf("%d\n", min_frustration);
    return 0;
}
