#define MAX_M 100
#define MAX_N 1000
typedef struct {
    int index;
    int count;
} Place;
int cmp(const void *a, const void *b) {
    Place *placeA = (Place *)a;
    Place *placeB = (Place *)b;
    if (placeA->count == placeB->count)
        return placeA->index - placeB->index;
    return placeB->count - placeA->count;
}
void process_dataset(int n, int m, int votes[MAX_N][MAX_M]) {
    Place places[MAX_M];
    for (int i = 0; i < m; i++) {
        places[i].index = i + 1;
        places[i].count = 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            places[j].count += votes[i][j];
        }
    }
    qsort(places, m, sizeof(Place), cmp);
    for (int i = 0; i < m; i++) {
        printf("%d", places[i].index);
        if (i < m - 1) {
            printf(" ");
        }
    }
    printf("\n");
}