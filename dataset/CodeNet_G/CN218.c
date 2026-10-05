void classify_students(int n, int scores[][3], char *result){
    for (int i = 0; i < n; i++) {
        int sum = scores[i][0] + scores[i][1] + scores[i][2];
        double avg_math_english = (scores[i][0] + scores[i][1]) / 2.0;
        double avg_all = sum / 3.0;
        if (scores[i][0] == 100 || scores[i][1] == 100 || scores[i][2] == 100 || avg_math_english >= 90.0 || avg_all >= 80.0) {
            result[i] = 'A';
        } else if (avg_all >= 70.0) {
            result[i] = 'A';
        } else if (avg_all >= 50.0 && (scores[i][0] >= 80 || scores[i][1] >= 80)) {
            result[i] = 'B';
        } else {
            result[i] = 'C';
        }
    }
}
int main(){
    int n;
    while (scanf("%d", &n), n != 0) {
        int scores[n][3];
        char result[n];
        for (int i = 0; i < n; i++) {
            scanf("%d %d %d", &scores[i][0], &scores[i][1], &scores[i][2]);
        }
        classify_students(n, scores, result);
        for (int i = 0; i < n; i++) {
            printf("%c\n", result[i]);
        }
    }
    return 0;
}