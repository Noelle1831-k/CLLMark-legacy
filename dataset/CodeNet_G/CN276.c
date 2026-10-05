int maxTeams(int c, int a, int n) {
    int teams = 0;
    while (true) {
        if (c >= 2 && a >= 1) {
            teams++;
            c -= 2;
            a -= 1;
        } else if (c >= 3) {
            teams++;
            c -= 3;
        } else if (c >= 1 && a >= 1 && n >= 1) {
            teams++;
            c -= 1;
            a -= 1;
            n -= 1;
        } else {
            break;
        }
    }
    return teams;
}