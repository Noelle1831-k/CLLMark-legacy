int calculate_average(int values[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum = sum + values[i];
    }
    return sum / size;
}