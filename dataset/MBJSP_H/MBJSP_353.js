function removeColumn(list1, n) {
    return list1.map(item => item.filter((x, i) => i !== n));
}
