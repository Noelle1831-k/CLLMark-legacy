function findRotationCount(a) {
    let n = 0;
    for (let i = 0; i < a.length; i++) {
        if (a[i] > a[(n + 1)]) {
            return n + 1;
        }
        n++;
    }
    return 0;
}
