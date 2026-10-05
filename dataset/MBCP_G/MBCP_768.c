bool checkOddParity(int x) {
    bool parity = false;
    while (x) {
        parity = !parity;
        x = x & (x - 1);
    }
    return parity;
}