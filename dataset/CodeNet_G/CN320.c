void sort_pairs(int pairs[6][2]) {
    for (int i = 0; i < 6; i++) {
        if (pairs[i][0] > pairs[i][1]) {
            int temp = pairs[i][0];
            pairs[i][0] = pairs[i][1];
            pairs[i][1] = temp;
        }
    }
}
int compare_pair(const void *a, const void *b) {
    const int *pairA = (const int *)a;
    const int *pairB = (const int *)b;
    if (pairA[0] != pairB[0]) return pairA[0] - pairB[0];
    return pairA[1] - pairB[1];
}
void check_cuboid(int pairs[6][2]) {
    sort_pairs(pairs);
    qsort(pairs, 6, sizeof(pairs[0]), compare_pair);
    if ((pairs[0][0] == pairs[1][0] && pairs[0][1] == pairs[1][1]) &&
        (pairs[2][0] == pairs[3][0] && pairs[2][1] == pairs[3][1]) &&
        (pairs[4][0] == pairs[5][0] && pairs[4][1] == pairs[5][1]) &&
        (pairs[0][0] == pairs[2][0] && pairs[0][1] == pairs[4][0]) &&
        (pairs[2][1] == pairs[4][1])) {
        printf("yes\n");
    } else {
        printf("no\n");
    }
}
