function findAdverbPosition(text) {
    let pattern = /\w+ly/g;
    let match = pattern.exec(text);
    if (match) {
        return [match.index, match.index + match[0].length, match[0]];
    }
}
