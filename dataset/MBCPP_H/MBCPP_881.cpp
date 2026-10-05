    int sum = 0;
    int firstEven = -1;
    int firstOdd = -1;
    for (int i = 0; i < list1.size(); i++) {
        int el = list1[i];
        if (el % 2 == 0) {
            if (firstEven == -1) {
                firstEven = el;
            }
        } else {
            if (firstOdd == -1) {
                firstOdd = el;
            }
        }
    }
    if (firstEven != -1) {
        sum += firstEven;
    }
    if (firstOdd != -1) {
        sum += firstOdd;
    }
    return sum;
}