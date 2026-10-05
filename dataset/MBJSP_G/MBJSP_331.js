function countUnsetBits(n) {
let count = 0;
    while (n > 0) {
        if ((n & 1) === 0) count++;
        n = Math.floor(n / 2);
    }
    return count;
}
