function findLongWord(text) {
    let regex = /[^a-zA-Z0-9]/g;
    let result = [];
    let words = text.split(regex);
    for (let i = 0; i < words.length; i++) {
        let word = words[i];
        if (word.length === 5) {
            result.push(word);
        }
    }
    return result;
}
