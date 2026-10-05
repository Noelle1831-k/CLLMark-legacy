function removeMatchingTuple(testlist1, testlist2) {
    return testList1.filter(item => {
        return testList2.every(item2 => {
            if (JSON.stringify(item) !== JSON.stringify(item2)) {
                return true;
            }
            return false;
        });
    });
}
