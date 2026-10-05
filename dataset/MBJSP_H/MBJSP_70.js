function getEqual(input, k) {
    let result = input.filter(function (x, i) {
      if (x.length === k) {
        return true;
      } else {
        return false;
      }
    });
    if (result.length === input.length) {
      return "All tuples have same length";
    } else {
      return "All tuples do not have same length";
    }
}
