function dropEmpty(dict1) {
  let result = {};
  result = Object.assign(result, dict1);

  for (let key in result) {
    if (result[key] === null) {
      delete result[key];
    }
  }

  return result;
}
