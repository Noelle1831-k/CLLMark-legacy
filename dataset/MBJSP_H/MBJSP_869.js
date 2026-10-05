function removeListRange(list1, leftrange, rigthrange) {
    let newList = [];
    list1.forEach(item => {
        if (leftrange <= item[0] && item[0] <= rigthrange) {
            newList.push(item);
        }
    });
    return newList;
}
