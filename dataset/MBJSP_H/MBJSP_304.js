function findElement(arr, ranges, rotations, index) {
  var i = 0;
  while (i < rotations) {
    // rotate the array
    // [1,2,3,4,5]
    // [0,1]
    var new_arr = [];
    for (var j = 0; j < arr.length; j++) {
      new_arr.push(arr[j]);
    }
    var temp = new_arr.splice(ranges[0][1], 1);
    new_arr.splice(ranges[1][0], 0, temp[0]);
    arr = new_arr;
    i++;
  }
  return arr[index];
}
