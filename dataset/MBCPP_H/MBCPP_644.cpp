    if (k > input.size()) {
        return input;
    }
    int i = 0;
    int j = k - 1;
    while (i < j) {
        int temp = input[i];
        input[i] = input[j];
        input[j] = temp;
        i++;
        j--;
    }
    return input;
}