function testDuplicate(arraynums) {
  for (let i = 0; i < arraynums.length; i++) {
    if (arraynums[i] == i) {
      return true;
    }
  }
  return false;
}
