function minLengthList(inputlist) {
    const result = inputList.reduce((acc, item) => {
        return item.length < acc.length ? item : acc;
    });

    return [result.length, result];
}
