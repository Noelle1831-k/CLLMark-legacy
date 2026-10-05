function convert(list) {
  let string = "";
  list.forEach(item => {
    let str = item + "";
    if (str === " ") {
      string = "";
    } else {
      string = string + str;
    }
  });
  return parseInt(string);
}
