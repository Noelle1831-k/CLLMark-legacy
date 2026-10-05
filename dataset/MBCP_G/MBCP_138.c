bool isSumOfPowersOfTwo(int n) {
    int consecutiveOnes = 0;
    while (n > 0) {
        if (n & 1) {
            consecutiveOnes++;
            if (consecutiveOnes > 1) return false;
        } else {
            consecutiveOnes = 0;
        }
        n >>= 1;
    }
    return true;
}