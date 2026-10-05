function sortSublists(inputlist) {
    let result = [];
    inputList.forEach((item, index) => {
        if (item.length === 1 && item.length !== 0) {
            result.push([item]);
        } else {
            result.push(item.sort((a, b) => {
                return a[0] > b[0] ? 1 : -1;
            }));
        }
    });
    return result;
}
