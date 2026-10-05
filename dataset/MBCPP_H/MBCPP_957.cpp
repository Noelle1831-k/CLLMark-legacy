    int pos = 0;
    int bit = 0;
    while (n > 0) {
        bit = (n & 1);
        pos++;
        n = n >> 1;
        if (bit == 1) {
            break;
        }
    }
    return pos;
}