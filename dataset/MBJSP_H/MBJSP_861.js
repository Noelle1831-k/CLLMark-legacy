function anagramLambda(texts, str) {
    return texts.filter(item => item.split('').sort().join('') === str.split('').sort().join(''));
}
