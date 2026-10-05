function swapList(newlist) {
  let old = newlist[0];
  newlist[0] = newlist[newlist.length - 1];
  newlist[newlist.length - 1] = old;
  return newlist;
}
