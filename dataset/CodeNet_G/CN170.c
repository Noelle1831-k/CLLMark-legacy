#define MAX_FOOD 10
#define MAX_LEN 21
typedef struct {
    char name[MAX_LEN];
    int weight;
    int strength;
} Food;
void solve(Food foods[], int n, char result[][MAX_LEN]) {
    int order[MAX_FOOD];
    for (int i = 0; i < n; ++i) {
        order[i] = i;
    }
    double min_center_of_gravity = 1e9;
    do {
        int valid = 1;
        int total_weight = 0;
        double current_center_of_gravity = 0.0;
        for (int i = 0; i < n; ++i) {
            int index = order[i];
            current_center_of_gravity += (i + 1) * foods[index].weight;
            total_weight += foods[index].weight;
            int supported_weight = 0;
            for (int j = i + 1; j < n; ++j) {
                supported_weight += foods[order[j]].weight;
            }
            if (foods[index].strength < supported_weight) {
                valid = 0;
                break;
            }
        }
        if (valid) {
            current_center_of_gravity /= total_weight;
            if (current_center_of_gravity < min_center_of_gravity) {
                min_center_of_gravity = current_center_of_gravity;
                for (int i = 0; i < n; ++i) {
                    strcpy(result[i], foods[order[i]].name);
                }
            }
        }
    } while (next_permutation(order, n));
}
int next_permutation(int *array, int size) {
    int i = size - 1;
    while (i > 0 && array[i - 1] >= array[i]) {
        --i;
    }
    if (i <= 0) return 0;
    int j = size - 1;
    while (array[j] <= array[i - 1]) {
        --j;
    }
    int temp = array[i - 1];
    array[i - 1] = array[j];
    array[j] = temp;
    j = size - 1;
    while (i < j) {
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
        ++i;
        --j;
    }
    return 1;
}