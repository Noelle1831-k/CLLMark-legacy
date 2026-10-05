function luckyNum(n) {
    return [
        1,
        3,
        7,
        9,
        13,
        15,
        21,
        25,
        31,
        33
    ].filter((item, index) => index < n);
}
