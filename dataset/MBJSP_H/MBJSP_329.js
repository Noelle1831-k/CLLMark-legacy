function negCount(list) {
    let negCount = 0;

    for (let i = 0; i < list.length; i++) {
        let num = list[i];
        if (num < 0) {
            negCount += 1;
        }
    }

    return negCount;
}
