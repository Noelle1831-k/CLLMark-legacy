function checkElement(list, element) {
  for (let i = 0; i < list.length; i++) {
    let o = list[i];
    if (o != element) {
      return false;
    }
  }
  return true;
}
