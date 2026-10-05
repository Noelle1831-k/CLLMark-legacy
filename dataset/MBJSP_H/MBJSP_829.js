function secondFrequent(input) {
    var freq = [];
    for (let i = 0; i < input.length; i++) {
        var item = input[i];
        if (freq.indexOf(item) == -1) {
            freq.push(item);
        }
        else {
            freq[freq.indexOf(item)] = item;
        }
    }

    return freq[freq.length - 2];
}
