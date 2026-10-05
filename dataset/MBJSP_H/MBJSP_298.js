function intersectionNestedLists(l1, l2) {
    return l2.map(item => {
        return item.filter(n => {
            return l1.includes(n)
        })
    })
}
