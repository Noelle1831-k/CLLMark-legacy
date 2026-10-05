function extractMissing(testlist, strtval, stopval) {
    var res = [];
    for (var i = 0; i < testList.length; i++) {
        if (testList[i][0] > strtVal) {
            res.push(new Array(strtVal, testList[i][0]));
            strtVal = testList[i][1];
        }
        if (strtVal < stopVal) {
            res.push(new Array(strtVal, stopVal));
        }
    }
    return res;
}
