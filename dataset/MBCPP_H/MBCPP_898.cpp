    vector<int> result;
    int i = 0;
    int j = 0;
    int length = numbers.size();
    while (i < length) {
        while (j < length && numbers[j] == numbers[i]) j++;
        if (j - i == n) result.push_back(numbers[i]);
        i = j;
    }
    return result;
}