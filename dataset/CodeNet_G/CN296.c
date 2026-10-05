void play_game(int N, int M, int *a, int *remaining) {
    int *students = malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        students[i] = 1;
    }
    int baton_holder = 0;
    for (int i = 0; i < M; i++) {
        int moves = a[i];
        if (moves % 2 == 0) {
            for (int count = 0; count < moves; count++) {
                do {
                    baton_holder = (baton_holder + 1) % N;
                } while (students[baton_holder] == 0);
            }
        } else {
            for (int count = 0; count < moves; count++) {
                do {
                    baton_holder = (baton_holder + N - 1) % N;
                } while (students[baton_holder] == 0);
            }
        }
        students[baton_holder] = 0;
        do {
            baton_holder = (baton_holder + 1) % N;
        } while (students[baton_holder] == 0);
    }
    for (int i = 0; i < N; i++) {
        remaining[i] = students[i];
    }
    free(students);
}
int main_task(int N, int M, int Q, int *a, int *q, int *results) {
    int *remaining = malloc(N * sizeof(int));
    play_game(N, M, a, remaining);
    for (int i = 0; i < Q; i++) {
        results[i] = remaining[q[i]];
    }
    free(remaining);
    return 0;
}