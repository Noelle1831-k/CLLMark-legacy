function findLiterals(text, pattern) {
    var patternLength = pattern.length;
    var patternStart = text.search(new RegExp(pattern, 'gi'));
    if (patternStart == -1) {
        return [];
    }
    return [pattern, patternStart, patternStart + patternLength];
}
