function getNumber(n, k) {
    const arr = [];
    if (n > 0) {
        arr.push(n);
    }
    while (arr.length < k) {
        const num = Math.floor(Math.random() * n) + 1;
        if (arr.includes(num)) {
            continue;
        }
        arr.push(num);
    }
    return arr[k - 1];
}
