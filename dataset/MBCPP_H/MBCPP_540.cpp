    int max = -1;
    int min = 100;
    int frequency = 0;
    for (int i = 0; i < arr.size(); i++) {
        frequency = 0;
        for (int j = 0; j < arr.size(); j++) {
            if (arr[i] == arr[j]) {
                frequency++;
            }
        }
        if (frequency > max) {
            max = frequency;
        }
        if (frequency < min) {
            min = frequency;
        }
    }
    return max - min;
}