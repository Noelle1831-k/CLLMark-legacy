int digitDistanceNums(int n1, int n2) {
    int distance = 0;
    while (n1 > 0 || n2 > 0) {
        int digit1 = n1 % 10;
        int digit2 = n2 % 10;
        distance += abs(digit1 - digit2);
        n1 /= 10;
        n2 /= 10;
    }
    return distance;
}