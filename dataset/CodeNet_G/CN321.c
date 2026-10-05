typedef struct {
    char item1[31];
    char item2[31];
    int count;
} Pair;
int comparePairs(const void *a, const void *b) {
    Pair *pairA = (Pair *)a;
    Pair *pairB = (Pair *)b;
    int cmp = strcmp(pairA->item1, pairB->item1);
    return cmp != 0 ? cmp : strcmp(pairA->item2, pairB->item2);
}
int main() {
    int N, F;
    scanf("%d %d", &N, &F);
    Pair pairs[4950];
    int pairCount = 0;
    for (int i = 0; i < N; i++) {
        int M;
        scanf("%d", &M);
        char items[M][31];
        for (int j = 0; j < M; j++) {
            scanf("%s", items[j]);
        }
        for (int j = 0; j < M; j++) {
            for (int k = j + 1; k < M; k++) {
                char *itemA = items[j];
                char *itemB = items[k];
                if (strcmp(itemA, itemB) > 0) {
                    char *temp = itemA;
                    itemA = itemB;
                    itemB = temp;
                }
                int found = 0;
                for (int p = 0; p < pairCount; p++) {
                    if (strcmp(pairs[p].item1, itemA) == 0 && strcmp(pairs[p].item2, itemB) == 0) {
                        pairs[p].count++;
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    strcpy(pairs[pairCount].item1, itemA);
                    strcpy(pairs[pairCount].item2, itemB);
                    pairs[pairCount].count = 1;
                    pairCount++;
                }
            }
        }
    }
    qsort(pairs, pairCount, sizeof(Pair), comparePairs);
    int validPairs = 0;
    for (int i = 0; i < pairCount; i++) {
        if (pairs[i].count >= F) {
            validPairs++;
        }
    }
    printf("%d\n", validPairs);
    for (int i = 0; i < pairCount; i++) {
        if (pairs[i].count >= F) {
            printf("%s %s\n", pairs[i].item1, pairs[i].item2);
        }
    }
    return 0;
}