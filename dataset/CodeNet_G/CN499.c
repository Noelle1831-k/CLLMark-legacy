int maxDaysToPlay(int L, int A, int B, int C, int D) {
    int daysForJapanese = (A + C - 1) / C;
    int daysForMath = (B + D - 1) / D;
    int daysToStudy = (daysForJapanese > daysForMath) ? daysForJapanese : daysForMath;
    return L - daysToStudy;
}