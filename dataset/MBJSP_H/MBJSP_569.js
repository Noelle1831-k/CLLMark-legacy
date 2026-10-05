function sortSublists(list1) {
  var result = [];

  return list1.map(item => {
    return (result.concat(item.slice(0, item.length))).sort();
  });
}
