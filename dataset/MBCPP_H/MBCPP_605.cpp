    if (num <= 0) {
        return false;
    }
    int i = 1;
    while (i < num) {
        if ((num & (1 << i)) == 0) {
            return true;
        }
        i <<= 1;
    }
    return false;
}