function findMax(testlist) {
    let max = 0;
    let current = 0;
    let sum = 0;
    testList.forEach(val => {
        sum += val[0];
        max = Math.max(max, val[1]);
    });
    return max;
}
