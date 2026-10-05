int count_candidates(int AW, int AH, char a[AH][AW+1], int BW, int BH, char b[BH][BW+1]) {
    int count = 0;
    for (int i = 0; i <= AH - BH; ++i) {
        for (int j = 0; j <= AW - BW; ++j) {
            int match = 1;
            for (int k = 0; k < BH && match; ++k) {
                for (int l = 0; l < BW; ++l) {
                    if (a[i+k][j+l] != '?' && b[k][l] != '?' && a[i+k][j+l] != b[k][l]) {
                        match = 0;
                        break;
                    }
                }
            }
            if (match) {
                count++;
            }
        }
    }
    return count;
}
