function packConsecutiveDuplicates(list1) {
    return list1.reduce((accum, item, index, arr) => {
        if (index === 0) {
            accum.push([item]);
        } else if (item === arr[index - 1]) {
            accum[accum.length - 1].push(item);
        } else {
            accum.push([item]);
        }
        return accum;
    }, []);
}
