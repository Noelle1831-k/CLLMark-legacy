function checkSubsetList(list1, list2) {
    for (var i1 = 0; i1 < list1.length; i1++) {
        for (var i2 = i1 + 1; i2 < list2.length; i2++) {
            if (list1[i1] <= list2[i2]) {
                return true;
            }
        }
        return false;
    }
    return false;
}
