void find_modes(int numbers[], int count) {
    int frequency[101] = {0};
    for (int i = 0; i < count; i++) {
        frequency[numbers[i]]++;
    }
    int max_frequency = 0;
    for (int i = 1; i <= 100; i++) {
        if (frequency[i] > max_frequency) {
            max_frequency = frequency[i];
        }
    }
    for (int i = 1; i <= 100; i++) {
        if (frequency[i] == max_frequency) {
            printf("%d ", i);
        }
    }
}
