long long convertRoomNumber(long long oldNumber) {
    long long newNumber = oldNumber;
    long long correction = 0;
    for (long long factor = 1; oldNumber / factor > 0; factor *= 10) {
        long long digit = (oldNumber / factor) % 10;
        if (digit >= 4) correction += factor;
        if (digit >= 6) correction += factor;
    }
    return newNumber + correction;
}