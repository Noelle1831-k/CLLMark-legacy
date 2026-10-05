function commonPrefix(arr, n) {
    let shortest = arr.sort((a, b) => a.length - b.length)[0];
    let longest = arr.sort((a, b) => a.length - b.length)[n - 1];
    let result = [];

    for (let i = 0; i < shortest.length; i++) {
        if (shortest[i] === longest[i]) {
            result.push(shortest[i]);
        } else {
            break;
        }
    }

    return result.join('');
}
