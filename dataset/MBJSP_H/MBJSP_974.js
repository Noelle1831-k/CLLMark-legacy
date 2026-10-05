function minSumPath(a) {
    if (a.length === 0) {
        return 0;
    }
    let min = a[0][0] + minSumPath(a.slice(1));
    for (let i = 0; i < a[0].length; i++) {
        let current = 0;
        for (let j = 0; j < a.length; j++) {
            current += a[j][i];
        }
        if (current < min) {
            min = current;
        }
    }
    return min;
}
