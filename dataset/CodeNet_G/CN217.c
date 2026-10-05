void findMaxDistance() {
    int n, pi, d1i, d2i;
    while (scanf("%d", &n) == 1 && n != 0) {
        int max_distance = -1;
        int patient_number = -1;
        for (int i = 0; i < n; i++) {
            scanf("%d %d %d", &pi, &d1i, &d2i);
            int total_distance = d1i + d2i;
            if (total_distance > max_distance) {
                max_distance = total_distance;
                patient_number = pi;
            }
        }
        printf("%d %d\n", patient_number, max_distance);
    }
}