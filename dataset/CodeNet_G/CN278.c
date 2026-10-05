#define MAX_N 1000000
#define MAX_LEADERS 100
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}
void execute_queries(int N, int Q, int scores[], char operations[Q][10], int values[Q]) {
    int leaders[MAX_LEADERS];
    int leaders_count = 0;
    int non_participants[MAX_N];
    int query_result[Q];
    int i, j, k, r, x;
    for (i = 0; i < Q; i++) {
        if (operations[i][0] == 'A') {
            leaders[leaders_count++] = values[i];
        } else if (operations[i][0] == 'R') {
            for (j = 0; j < leaders_count; j++) {
                if (leaders[j] == values[i]) {
                    leaders[j] = leaders[leaders_count - 1];
                    leaders_count--;
                    break;
                }
            }
        } else if (operations[i][0] == 'C') {
            x = values[i];
            if (leaders_count == 0) {
                query_result[i] = (x < N) ? -1 : 0;
                continue;
            }
            qsort(leaders, leaders_count, sizeof(int), compare);
            int left = 0, right = 1000000000, mid, notPartCount;
            while (left < right) {
                mid = left + (right - left) / 2;
                notPartCount = 0;
                for (j = 0; j < N; j++) {
                    int score = scores[j];
                    int canParticipate = 0;
                    for (k = 0; k < leaders_count; k++) {
                        int leaderScore = scores[leaders[k]];
                        if (score >= leaderScore - mid && score <= leaderScore) {
                            canParticipate = 1;
                            break;
                        }
                    }
                    if (!canParticipate) {
                        notPartCount++;
                        if (notPartCount > x) break;
                    }
                }
                if (notPartCount > x) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
            query_result[i] = (right == 1000000000) ? -1 : right;
        }
    }
    for (i = 0; i < Q; i++) {
        if (operations[i][0] == 'C') {
            if (query_result[i] == -1) {
                printf("NA\n");
            } else {
                printf("%d\n", query_result[i]);
            }
        }
    }
}