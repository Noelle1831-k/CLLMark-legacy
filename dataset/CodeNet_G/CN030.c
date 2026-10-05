int countCombinations(int n, int s) {
    int count = 0;
    int nums[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    void findCombinations(int index, int remaining, int currentSum) {
        if (remaining == 0 && currentSum == s) {
            count++;
            return;
        }
        if (remaining == 0 || currentSum > s || index > 9) {
            return;
        }
        findCombinations(index + 1, remaining, currentSum);
        if (currentSum + nums[index] <= s) {
            findCombinations(index + 1, remaining - 1, currentSum + nums[index]);
        }
    }
    findCombinations(0, n, 0);
    return count;
}