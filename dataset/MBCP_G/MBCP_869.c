#define MAX_SUBLISTS 100
#define MAX_ELEMENTS 100
void removeListRange(int list1[MAX_SUBLISTS][MAX_ELEMENTS], int sizes[MAX_SUBLISTS], int num_lists, int leftRange, int rightRange, int result[MAX_SUBLISTS][MAX_ELEMENTS], int *result_sizes, int *result_count) {
    *result_count = 0;
    for (int i = 0; i < num_lists; i++) {
        int is_within_range = 1;
        for (int j = 0; j < sizes[i]; j++) {
            if (list1[i][j] < leftRange || list1[i][j] > rightRange) {
                is_within_range = 0;
                break;
            }
        }
        if (is_within_range) {
            for (int j = 0; j < sizes[i]; j++) {
                result[*result_count][j] = list1[i][j];
            }
            result_sizes[*result_count] = sizes[i];
            (*result_count)++;
        }
    }
}