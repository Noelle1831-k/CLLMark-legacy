function checkKElements(testlist, k) {
    return testList.every((item, index) => {
        return testList[index].every(item => {
            return item === k;
        })
    })
}
