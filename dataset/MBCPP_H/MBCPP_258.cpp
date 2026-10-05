    int count = 0;
    int oddNum = 0;
    for (int num : arrayNums) {
        if (num % 2 == 0) {
            count++;
        } else {
            oddNum++;
        }
    }
    return oddNum;
}