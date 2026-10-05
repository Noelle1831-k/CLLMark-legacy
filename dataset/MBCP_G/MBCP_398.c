int sumOfDigits(int *nums, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        int number = abs(nums[i]);
        while (number > 0) {
            sum += number % 10;
            number /= 10;
        }
    }
    return sum;
}