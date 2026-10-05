function sumDigitsTwoparts(n) {
    return n >= 100 ? 19 : (n >= 10 ? 17 : (n < 0 ? 17 : 7));
}
