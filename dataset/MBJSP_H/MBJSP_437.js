function removeOdd(str1) {
    let words = str1.split("");
    for (let i = 0; i < words.length; i++) {
        if (words[i] % 2 !== 0) {
            words.splice(i, 1);
        }
    }
    return words.join("");
}
