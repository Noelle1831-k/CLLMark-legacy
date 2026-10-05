void solve(int p[8]) {
    int rides[] = {4, 4, 2, 2, 1, 1, 1, 1};
    int minUnfortunate = INT_MAX;
    int bestV = INT_MAX;
    int permutation[8] = {0, 1, 2, 3, 4, 5, 6, 7};
    do {
        int unfortunate = 0;
        for (int i = 0; i < 8; i++) {
            if (p[i] > rides[permutation[i]]) {
                unfortunate += p[i] - rides[permutation[i]];
            }
        }
        int currentV = 0;
        for (int i = 0; i < 8; i++) {
            currentV = currentV * 10 + rides[permutation[i]];
        }
        if (unfortunate < minUnfortunate || (unfortunate == minUnfortunate && currentV < bestV)) {
            minUnfortunate = unfortunate;
            bestV = currentV;
        }
    } while (next_permutation(permutation, permutation + 8));
    for (int i = 0; i < 8; i++) {
        printf("%d ", bestV % 10);
        bestV /= 10;
    }
    printf("\n");
}
int next_permutation(int *first, int *last) {
    if (first == last) return 0;
    int *i = last;
    if (first == --i) return 0;
    while (1) {
        int *ii = i;
        if (*--i < *ii) {
            int *j = last;
            while (!(*i < *--j));
            int tmp = *i;
            *i = *j;
            *j = tmp;
            ++i;
            j = last;
            while (i < --j) {
                tmp = *i;
                *i = *j;
                *j = tmp;
                ++i;
            }
            return 1;
        }
        if (i == first) {
            while (first < --last) {
                int tmp = *first;
                *first = *last;
                *last = tmp;
                ++first;
            }
            return 0;
        }
    }
}
