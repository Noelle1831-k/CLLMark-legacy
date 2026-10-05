    int len = testStr.size();
    int max = 0;
    int count = 0;
    for (int i = 0; i < len; i++) {
        if (testStr[i] == ' ') {
            count = 0;
            continue;
        }
        if (testStr[i] >= 'A' && testStr[i] <= 'Z') {
            count++;
        } else {
            count = 0;
        }
        if (max < count) {
            max = count;
        }
    }
    return max;
}