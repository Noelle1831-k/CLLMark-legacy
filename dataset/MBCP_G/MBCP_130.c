void maxOccurrences(int nums[], int length, int *element, int *frequency) {
    int max_count = 0;
    int current_count = 1;
    int max_element = nums[0];
    for (int i = 0; i < length - 1; i++) {
        current_count = 1;
        for (int j = i + 1; j < length; j++) {
            if (nums[i] == nums[j]) {
                current_count++;
            }
        }
        if (current_count > max_count) {
            max_count = current_count;
            max_element = nums[i];
        }
    }
    *element = max_element;
    *frequency = max_count;
}