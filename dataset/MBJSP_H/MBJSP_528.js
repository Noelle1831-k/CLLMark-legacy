function minLength(list1) {
    let min = list1[0].length;
    for (let i = 1; i < list1.length; i++) {
        if (list1[i].length < min) {
            min = list1[i].length;
        }
    }
    return min === list1[0].length ? [1, list1[0]] : [1, list1.filter(item => item.length === min)];
}
