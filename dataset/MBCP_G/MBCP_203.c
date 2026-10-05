int hammingDistance(int n1, int n2) {
    int xor_value = n1 ^ n2;
    int distance = 0;
    while (xor_value) {
        distance += xor_value & 1;
        xor_value >>= 1;
    }
    return distance;
}