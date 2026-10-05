function positionMax(list1) {
    let max = list1[0];
    let position = [0];
    for (let i = 1; i < list1.length; i++) {
        if (list1[i] > max) {
            max = list1[i];
            position = [i];
        } else if (list1[i] === max) {
            position.push(i);
        }
    }
    return position;
}
