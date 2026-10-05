int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int getLcm(int* l, int size) {
    if (size < 1) return 0;
    int lcm = l[0];
    for (int i = 1; i < size; i++) {
        lcm = (lcm * l[i]) / gcd(lcm, l[i]);
    }
    return lcm;
}