function countElementFreq(testtuple) {
    let count = {};
    for (let item of testTuple) {
        if (typeof (item) === 'number') {
            if (count[item]) {
                count[item]++;
            } else {
                count[item] = 1;
            }
        } else {
            for (let innerItem of item) {
                if (typeof (innerItem) === 'number') {
                    if (count[innerItem]) {
                        count[innerItem]++;
                    } else {
                        count[innerItem] = 1;
                    }
                }
            }
        }
    }
    return count;
}
