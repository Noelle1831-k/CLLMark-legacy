function findEvenPair(a, n) {
    if (n % 2 === 0) return 0;
    const temp = [];
    const arr = [...a];
    for (let i = 0; i < arr.length; i++) {
        for (let j = i + 1; j < arr.length; j++) {
            if (arr[i] === arr[j]) continue;
            temp.push(arr[i] + arr[j]);
        }
    }
    return temp.filter(item => item % 2 === 0).length;
}
