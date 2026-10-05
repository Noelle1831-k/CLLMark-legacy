function positionMin(list1) {
    let min = list1[0];
    let position = [];

    for (let i = 0; i < list1.length; i++) {
        if (list1[i] < min) {
            min = list1[i];
            position = [];
        }

        if (list1[i] === min) {
            position.push(i);
        }
    }

    return position;
}
