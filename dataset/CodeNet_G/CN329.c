#define MAX_N 500
#define MAX_LADDERS 10000
int N;
int ladders[MAX_N - 1][MAX_N - 1];
int path[MAX_N];
int result[MAX_N - 1];
int min_order[MAX_N - 1];
bool visited[MAX_N - 1];
bool found = false;
void copy_result(int *source) {
    for (int i = 0; i < N - 1; i++) {
        result[i] = source[i];
    }
}
bool is_in_lexical_order(int *order) {
    for (int i = 0; i < N - 1; i++) {
        if (order[i] < min_order[i]) {
            return true;
        }
        if (order[i] > min_order[i]) {
            return false;
        }
    }
    return false;
}
void backtrack(int depth) {
    if (depth == N - 1) {
        int current_pos = 0;
        for (int i = 0; i < N - 1; i++) {
            if (ladders[result[i]][current_pos]) {
                current_pos++;
            } else if (current_pos > 0 && ladders[result[i]][current_pos - 1]) {
                current_pos--;
            }
        }
        if (current_pos == N - 1) {
            if (!found || is_in_lexical_order(result)) {
                copy_result(result);
                found = true;
            }
        }
        return;
    }
    for (int i = 0; i < N - 1; i++) {
        if (!visited[i]) {
            visited[i] = true;
            result[depth] = i;
            backtrack(depth + 1);
            visited[i] = false;
        }
    }
}
void solve() {
    for (int i = 0; i < N - 1; i++) {
        min_order[i] = i;
    }
    backtrack(0);
    if (found) {
        printf("yes\n");
        for (int i = 0; i < N - 1; i++) {
            printf("%d\n", result[i] + 1);
        }
    } else {
        printf("no\n");
    }
}
