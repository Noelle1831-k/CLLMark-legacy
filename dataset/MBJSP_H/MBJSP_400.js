function extractFreq(testlist) {
    let count = 0;

    for (let i = 0; i < testList.length; i++) {
        if (!testList[i].includes(i)) {
            count++;
        }
    }
    return count;
}
