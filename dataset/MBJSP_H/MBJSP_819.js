function countDuplic(lists) {
    let result = [];
    let counter = 1;
    let temp = [];
    let temp2 = [];
    for (let i = 0; i < lists.length; i++) {
        if (lists[i] === lists[i + 1]) {
            counter++;
        } else {
            temp.push(lists[i]);
            temp2.push(counter);
            counter = 1;
        }
    }
    result.push(temp);
    result.push(temp2);
    return result;
}
