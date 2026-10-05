void find_obese_students() {
    int si;
    float wi, hi;
    while (scanf("%d,%f,%f", &si, &wi, &hi) != EOF) {
        float bmi = wi / (hi * hi);
        if (bmi >= 25.0) {
            printf("%d\n", si);
        }
    }
}