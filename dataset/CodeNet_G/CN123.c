void determine_rank(double t1, double t2) {
    if (t1 < 35.50 && t2 < 71.00) {
        printf("AAA\n");
    } else if (t1 < 37.50 && t2 < 77.00) {
        printf("AA\n");
    } else if (t1 < 40.00 && t2 < 83.00) {
        printf("A\n");
    } else if (t1 < 43.00 && t2 < 89.00) {
        printf("B\n");
    } else if (t1 < 50.00 && t2 < 105.00) {
        printf("C\n");
    } else if (t1 < 55.00 && t2 < 116.00) {
        printf("D\n");
    } else if (t1 < 70.00 && t2 < 148.00) {
        printf("E\n");
    } else {
        printf("NA\n");
    }
}