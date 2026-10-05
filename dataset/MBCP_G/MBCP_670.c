bool decreasingTrend(int nums[], int size) {
    bool hasDecreasingTrend = true;
    for (int i = 1; i < size; i++) {
        if (nums[i] > nums[i - 1]) {
            hasDecreasingTrend = false;
            break;
        }
    }
    return hasDecreasingTrend;
}