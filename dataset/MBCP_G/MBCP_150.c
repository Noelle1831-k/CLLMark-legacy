bool doesContainB(int a, int b, int c) {
    if (b == 0) {
        return (a == c);
    }
    return ((c - a) % b == 0) && ((c - a) / b >= 0);
}