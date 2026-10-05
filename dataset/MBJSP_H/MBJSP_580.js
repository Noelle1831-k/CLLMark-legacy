function extractEven(testtuple) {
    let result = [];
    testTuple.forEach(item => {
        if (Array.isArray(item)) {
            result.push(extractEven(item));
        } else if (item % 2 === 0) {
            result.push(item);
        }
    });
    return result;
}
