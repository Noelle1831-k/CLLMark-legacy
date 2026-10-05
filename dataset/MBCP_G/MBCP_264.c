int dogAge(int hAge) {
    if (hAge <= 2) {
        return hAge * 10.5;
    } else {
        return 21 + (hAge - 2) * 4;
    }
}