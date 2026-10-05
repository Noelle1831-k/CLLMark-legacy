int count_satisfying_people(int N, int X, int* A, int Y, int* B, int Z, int* C) {
    int count = 0;
    int people[101] = {0};
    for (int i = 0; i < Z; i++) {
        people[C[i]] = 1;
    }
    for (int i = 0; i < X; i++) {
        if (people[A[i]] == 1) {
            people[A[i]] = 0;
        }
    }
    for (int i = 0; i < N; i++) {
        if (people[i + 1] == 1) {
            count++;
        }
    }
    for (int i = 0; i < Y; i++) {
        if (people[B[i]] == 0) {
            count++;
        }
    }
    return count;
}