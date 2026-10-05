function posNos(list1) {
  var newList = [];
  var temp;
  var count;

  if(list1.length === 1) {
    return list1[0];
  }

  for(var i = 0; i < list1.length; i++) {
    if(list1[i] > 0) {
      temp = list1[i];
      newList.push(temp);
    }
  }
  if(newList.length === 1) {
    return newList[0];
  } else {
    return newList;
  }
}
