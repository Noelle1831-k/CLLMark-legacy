void convertYear(int E, int Y) {
    if (E == 0) { 
        if (Y >= 1868 && Y <= 1911) {
            printf("M%d\n", Y - 1867);
        } else if (Y == 1912) {
            printf("T1\n");
        } else if (Y >= 1913 && Y <= 1925) {
            printf("T%d\n", Y - 1911);
        } else if (Y == 1926) {
            printf("S1\n");
        } else if (Y >= 1927 && Y <= 1988) {
            printf("S%d\n", Y - 1925);
        } else if (Y == 1989) {
            printf("H1\n");
        } else if (Y >= 1990 && Y <= 2016) {
            printf("H%d\n", Y - 1988);
        }
    } else if (E == 1) { 
        printf("%d\n", 1867 + Y);
    } else if (E == 2) { 
        printf("%d\n", 1911 + Y);
    } else if (E == 3) { 
        printf("%d\n", 1925 + Y);
    } else if (E == 4) { 
        printf("%d\n", 1988 + Y);
    }
}