function removeDuplicate(list1) {
    list1.sort();
    for (let i = 0; i < list1.length; i++) {
        for (let j = i + 1; j < list1.length; j++) {
            if (list1[i].toString() === list1[j].toString()) {
                list1.splice(j, 1);
            }
        }
    }
    return list1;
}
