    int max = 0;
    for (auto v : testList) {
        int diff = 0;
        int num1 = v[0];
        int num2 = v[1];
        if (num1 > num2) {
            diff = num1 - num2;
        } else {
            diff = num2 - num1;
        }
        if (diff > max) {
            max = diff;
        }
    }
    return max;
}