function checkValue(dict, n) {
  const keys = Object.keys(dict);

  for (let i = 0; i < keys.length; i++) {
    const key = keys[i];
    const value = dict[key];

    if (value !== n) {
      return false;
    }
  }

  return true;
}
