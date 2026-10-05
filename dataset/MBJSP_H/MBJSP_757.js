function countReversePairs(testlist) {
    var res = 0;
    for (var idx = 0; idx < testList.length - 1; ++idx) {
        for (var idxn = testList.length - 1; idxn > idx; --idxn) {
            if (testList[idxn].charAt(testList[idxn].length - 1) == testList[idx].charAt(0)) {
                ++res;
            }
        }
    }
    return res + "";
}
