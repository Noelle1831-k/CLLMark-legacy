    int maxSum = 0;
    int curSum = 0;
    int start = 0, end = 0;
    for(int i = 0; i < size; i++) {
        curSum += a.at(i);
        if(curSum < 0) {
            start = i + 1;
            curSum = 0;
        }
        if(curSum > maxSum) {
            maxSum = curSum;
            end = i;
        }
    }
    return end - start + 1;
}