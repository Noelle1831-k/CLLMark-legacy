function findOddPair(a, n) {
    let count = 0;
    for (let i = 0; i < a.length; i++) {
        for (let j = i; j < a.length; j++) {
            if ((a[i] ^ a[j]) % 2) {
                count++;
            }
        }
    }
    return count;
}
