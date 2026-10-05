void calculateHitAndBlow(int* a, int* b, int* hit, int* blow) {
    int usedInA[4] = {0};
    int usedInB[4] = {0};
    *hit = 0;
    *blow = 0;
    for (int i = 0; i < 4; i++) {
        if (a[i] == b[i]) {
            (*hit)++;
            usedInA[i] = 1;
            usedInB[i] = 1;
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (!usedInA[i] && !usedInB[j] && a[i] == b[j]) {
                (*blow)++;
                usedInA[i] = 1;
                usedInB[j] = 1;
                break;
            }
        }
    }
}
