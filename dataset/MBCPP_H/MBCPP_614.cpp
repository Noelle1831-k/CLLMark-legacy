    int sum = 0;
    for (vector<int> element : testList) {
        for (int i : element) {
            sum += i;
        }
    }
    return sum;
}