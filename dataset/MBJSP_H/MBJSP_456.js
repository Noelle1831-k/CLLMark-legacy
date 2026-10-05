function reverseStringList(stringlist) {
    return stringlist.map(item => item.split("").reverse().join(""));
}
