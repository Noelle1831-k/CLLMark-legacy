function nCommonWords(text, n) {
    let arr = text.split(' ');
    let result = [];
    for (let i = 0; i < arr.length; i++) {
        let word = arr[i];
        let count = 0;
        for (let j = 0; j < n; j++) {
            if (word === arr[j]) {
                count++;
            }
        }
        if (count > 0) {
            result.push([word, count]);
        }
    }
    return result;
}
