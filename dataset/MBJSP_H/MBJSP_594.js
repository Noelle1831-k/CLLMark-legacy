function diffEvenOdd(list1) {
    const list2 = list1.filter((item) => {
        if (item % 2 === 0) {
            return item;
        }
    });
    if (list2.length > 0) {
        return list2[0] - 1;
    }
}
