function snakeToCamel(word) {
  return word.split("_")
    .map(item => item.charAt(0).toUpperCase() + item.slice(1).toLowerCase())
    .join("");
}
