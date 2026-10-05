vector<int> result;
for (int num = startnum; num <= endnum; ++num) {
    int originalNum = num;
    bool isDivisible = true;
    while (originalNum > 0) {
        int digit = originalNum % 10;
        if (digit == 0 || num % digit != 0) {
            isDivisible = false;
            break;
        }
        originalNum /= 10;
    }
    if (isDivisible) {
        result.push_back(num);
    }
}
return result;
}