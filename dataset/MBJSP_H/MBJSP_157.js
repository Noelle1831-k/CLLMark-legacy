function encodeList(list1) {
    if (list1.length > 1) {
        var result = [];
        var item = list1[0];
        var count = 1;

        for (var j = 1; j < list1.length; j++) {
            var item2 = list1[j];
            if (item2 != item) {
                result.push([count, item]);
                count = 1;
                item = item2;
            }
            else {
                count++;
            }
        }
        result.push([count, item]);
        return result;
    }
    return [[1, list1]];
}
