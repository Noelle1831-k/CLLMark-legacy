function freqCount(list1) {
    let frequency = {};
    for (let i = 0; i < list1.length; i++) {
        if (!frequency[list1[i]]) {
            frequency[list1[i]] = 1;
        } else {
            frequency[list1[i]]++;
        }
    }

    return frequency;
}
