function numCommDiv(x, y) {
    let count = 0;
    for (let i = 1; i < y; i++) {
        if (x % i === 0 && y % i === 0) {
            count++;
        }
    }
    return count;
}
