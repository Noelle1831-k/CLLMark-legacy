#define MAX 100005
int parent[MAX];
int size[MAX];
int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}
void unionSets(int a, int b) {
    int rootA = find(a);
    int rootB = find(b);
    if (rootA != rootB) {
        if (size[rootA] < size[rootB]) {
            parent[rootA] = rootB;
            size[rootB] += size[rootA];
        } else {
            parent[rootB] = rootA;
            size[rootA] += size[rootB];
        }
    }
}
void sieve(bool isPrime[], int n) {
    for (int i = 2; i <= n; i++) {
        isPrime[i] = true;
    }
    for (int p = 2; p * p <= n; p++) {
        if (isPrime[p] == true) {
            for (int i = p * p; i <= n; i += p) {
                isPrime[i] = false;
            }
        }
    }
}
void coprimeSort(int N, int a[]) {
    bool isPrime[MAX];
    sieve(isPrime, MAX - 1);
    for (int i = 2; i < MAX; i++) {
        parent[i] = i;
        size[i] = 1;
    }
    for (int i = 0; i < N; i++) {
        int num = a[i];
        for (int p = 2; p * p <= num; p++) {
            if (num % p == 0 && isPrime[p]) {
                unionSets(a[i], p);
                while (num % p == 0) num /= p;
            }
        }
        if (num > 1 && isPrime[num]) {
            unionSets(a[i], num);
        }
    }
    int sorted[MAX];
    for (int i = 0; i < N; i++) {
        sorted[i] = a[i];
    }
    qsort(sorted, N, sizeof(int), (int (*)(const void *, const void *)) compare);
    for (int i = 0; i < N; i++) {
        if (find(a[i]) != find(sorted[i])) {
            printf("0\n");
            return;
        }
    }
    printf("1\n");
}
int compare(const int *a, const int *b) {
    return (*a - *b);
}
