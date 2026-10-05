function getMaxOccuringChar(str1) {
    return str1.match(/[aeiou]/g).reduce((acc, char) => {
        return acc > char ? acc : char;
    }, -1);
}
