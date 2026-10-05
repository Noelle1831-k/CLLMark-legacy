function interleaveLists(list1, list2, list3) {
    var res = [];
    for (let i = 0; i < list1.length; i++) {
        res.push(list1[i]);
        res.push(list2[i]);
        res.push(list3[i]);
    }
    return res;
}
