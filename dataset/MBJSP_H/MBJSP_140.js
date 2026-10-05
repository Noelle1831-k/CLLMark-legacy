function extractSingly(testlist) {
    const result = [];
    testList.forEach(arr => {
        arr.forEach(number => {
            if (result.indexOf(number) === -1) {
                result.push(number);
            }
        });
    });
    return result;
}
