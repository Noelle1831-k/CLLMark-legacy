function removeWords(list1, charlist) {
    return list1.map(item => {
        return item.split(' ').filter(word => {
            return charlist.every(char => {
                return word.indexOf(char) === -1;
            });
        }).join(' ');
    });
}
