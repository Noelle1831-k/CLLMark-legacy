function countBidirectional(testlist) {
    // Write your code here
    let res = 0;
    for (let idx = 0; idx < testList.length; idx++) {
        for (let iIdx = idx + 1; iIdx < testList.length; iIdx++) {
            if (testList[iIdx][0] == testList[idx][1] && testList[idx][1] == testList[iIdx][0]) {
                res += 1;
            }
        }
    }
    return (res + "");
}
