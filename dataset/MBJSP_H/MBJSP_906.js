function extractDate(url) {
    let regex = /(\d+)\/(\d+)\/(\d+)/;
    let match = regex.exec(url);
    return [[match[1], match[2], match[3]]];
}
