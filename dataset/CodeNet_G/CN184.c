void process_ages() {
    int n;
    while (scanf("%d", &n), n != 0) {
        int age;
        int age_groups[7] = {0};
        for (int i = 0; i < n; i++) {
            scanf("%d", &age);
            if (age < 10) age_groups[0]++;
            else if (age < 20) age_groups[1]++;
            else if (age < 30) age_groups[2]++;
            else if (age < 40) age_groups[3]++;
            else if (age < 50) age_groups[4]++;
            else if (age < 60) age_groups[5]++;
            else age_groups[6]++;
        }
        for (int i = 0; i < 7; i++) {
            printf("%d\n", age_groups[i]);
        }
    }
}