void classify_parts(int a, int b, int c, int N, int tests[][4]) {
    int total_parts = a + b + c;
    int defect_status[total_parts + 1];
    int normal_status[total_parts + 1];
    for (int i = 1; i <= total_parts; i++) {
        defect_status[i] = 0;
        normal_status[i] = 0;
    }
    for (int i = 0; i < N; i++) {
        int power = tests[i][0];
        int motor = tests[i][1];
        int cable = tests[i][2];
        int result = tests[i][3];
        if (result == 1) {
            normal_status[power] = 1;
            normal_status[motor] = 1;
            normal_status[cable] = 1;
        } else {
            defect_status[power]++;
            defect_status[motor]++;
            defect_status[cable]++;
        }
    }
    for (int i = 1; i <= total_parts; i++) {
        if (normal_status[i]) {
            printf("1\n");
        } else if (defect_status[i] > 0 && defect_status[i] <= N) {
            printf("0\n");
        } else {
            printf("2\n");
        }
    }
}