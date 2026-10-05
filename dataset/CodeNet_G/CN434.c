#define TOTAL_STUDENTS 30
void find_non_submitters(int submitters[], int size, int *non_submitter1, int *non_submitter2) {
    int present[TOTAL_STUDENTS + 1] = {0};
    for (int i = 0; i < size; i++) {
        present[submitters[i]] = 1;
    }
    int found = 0;
    for (int i = 1; i <= TOTAL_STUDENTS; i++) {
        if (!present[i]) {
            if (found == 0) {
                *non_submitter1 = i;
                found++;
            } else {
                *non_submitter2 = i;
                break;
            }
        }
    }
}