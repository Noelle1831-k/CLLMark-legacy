function sortMixedList(mixedlist) {
const numbers = mixedlist.filter(item => typeof item === 'number').sort((a, b) => a - b);
    const strings = mixedlist.filter(item => typeof item === 'string').sort();
    return [...numbers, ...strings];
}
