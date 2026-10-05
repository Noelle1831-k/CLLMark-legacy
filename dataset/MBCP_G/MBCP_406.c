char* findParity(int x) {
    int count = 0;
    while (x) {
        count += x & 1;
        x >>= 1;
    }
    return (count % 2 == 0) ? "Even Parity" : "Odd Parity";
}