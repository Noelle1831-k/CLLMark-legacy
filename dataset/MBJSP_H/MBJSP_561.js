function assignElements(testlist) {
    return testList.reduce((prev, [first, second]) => {
        if (!prev[first]) prev[first] = [];
        if (!prev[second]) prev[second] = [];
        prev[first].push(second);
        return prev;
    }, {});
}
