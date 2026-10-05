function minDifference(testlist) {
    let minDiff = Infinity;
    testList.forEach(item => {
        let diff = Math.abs(item[0] - item[1]);
        if (diff < minDiff) {
            minDiff = diff;
        }
    });
    return minDiff;
}
