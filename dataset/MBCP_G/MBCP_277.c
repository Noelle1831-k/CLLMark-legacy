#define MAX 100
typedef struct {
    char key[MAX];
    int value;
} Pair;
void dictFilter(Pair dict[], int size, int n, Pair result[], int *result_size) {
    int res_index = 0;
    for (int i = 0; i < size; i++) {
        if (dict[i].value >= n) {
            strcpy(result[res_index].key, dict[i].key);
            result[res_index].value = dict[i].value;
            res_index++;
        }
    }
    *result_size = res_index;
}