function textUppercaseLowercase(text) {
  if (!text) return 'Not matched!';

  let regex = /([A-Z])([a-z])([A-Z])/g;
  let matches = [];
  let match;

  do {
    match = regex.exec(text);
    if (match) {
      matches.push(match.join(''));
    }
  } while (match);

  if (matches.length === 0) return 'Not matched!';
  return 'Found a match!';
}
