function minProductTuple(list1) {
    let list2 = list1.map(list => list.reduce((acc, val) => acc * val));
    return Math.min(...list2);
}
