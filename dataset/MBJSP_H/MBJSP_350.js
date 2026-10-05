function minimumLength(s) {
  let len = 0;

  for (let i = 0; i < s.length; i++) {
    let count = 0;

    for (let j = 0; j < s.length; j++) {
      if (s[i] === s[j]) {
        count += 1;
      }
    }

    if (count === 1) {
      len += 1;
    }
  }

  return len;
}
