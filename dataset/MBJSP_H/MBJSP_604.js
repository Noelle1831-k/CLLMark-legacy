function reverseWords(s) {
    let words = s.split(' ');
    let reversed = [];
    for (let i = words.length - 1; i >= 0; i--) {
        reversed.push(words[i]);
    }
    return reversed.join(' ');
}
