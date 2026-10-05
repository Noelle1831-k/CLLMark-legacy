    vector<int>numbers;
    for (int n = startnum; n <= endnum; n++) {
        int num = n;
        int rem = 0;
        while (num) {
            rem = num % 10;
            if (rem == 0 || n % rem != 0)
                break;
            num /= 10;
        }
        if (num == 0)
            numbers.push_back(n);
    }
    return numbers;
}