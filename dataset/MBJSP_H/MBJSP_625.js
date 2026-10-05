function swapList(newlist) {
    let temp = newlist[0];
    newlist[0] = newlist[newlist.length - 1];
    newlist[newlist.length - 1] = temp;

    return newlist;
}
