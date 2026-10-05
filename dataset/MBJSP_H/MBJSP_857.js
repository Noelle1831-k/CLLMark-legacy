function listifyList(list1) {
    return list1.map(item => {
        return item.split('').reduce((acc, curr) => {
            return [...acc, curr];
        }, []);
    })
}
