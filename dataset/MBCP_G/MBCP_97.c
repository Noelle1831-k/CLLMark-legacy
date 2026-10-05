void frequencyLists(int lists[][4], int rows, int output[][2], int *outputSize) {
    int frequency[100] = {0}; 
    int maxNumber = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 4; j++) {
            int num = lists[i][j];
            frequency[num]++;
            if (num > maxNumber) {
                maxNumber = num;
            }
        }
    }
    int index = 0;
    for (int i = 0; i <= maxNumber; i++) {
        if (frequency[i] > 0) {
            output[index][0] = i;
            output[index][1] = frequency[i];
            index++;
        }
    }
    *outputSize = index;
}