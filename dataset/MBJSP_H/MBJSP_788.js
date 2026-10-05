function newTuple(testlist, teststr) {
    const newTuple = [];

    for (const item in testList) {
        if (testList.hasOwnProperty(item)) {
            newTuple.push(testList[item]);
        }
    }

    newTuple.push(testStr);
    return newTuple;
}
