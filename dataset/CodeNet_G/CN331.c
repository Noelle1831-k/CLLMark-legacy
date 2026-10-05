int determineTimePeriod(int H, int R) {
    if (H > R) {
        return 1; 
    } else if (H == -R || H == R) {
        return 0; 
    } else if (H < -R) {
        return -1; 
    }
    return 0; 
}