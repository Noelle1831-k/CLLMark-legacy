function snakeToCamel(word) {
  const wordSplit = word.split("_");
  let camelizedWord = "";
  wordSplit.forEach((item, i) => {
    if (i === 0) {
      camelizedWord += item.charAt(0).toUpperCase() + item.slice(1);
    } else {
      camelizedWord += `${item.charAt(0).toUpperCase()}${item.slice(1)}`
    }
  });
  return camelizedWord;
}
