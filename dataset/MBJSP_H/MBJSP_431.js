function commonElement(list1, list2) {
    return list1.every(item => list2.indexOf(item) === -1)
        ? null : true;
}
