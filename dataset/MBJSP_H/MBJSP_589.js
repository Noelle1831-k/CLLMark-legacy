function perfectSquares(a, b) {
  const squares = [];
  for (let i = Math.floor(a); i <= Math.ceil(b); i++) {
    if (Math.sqrt(i) % 1 === 0) {
      squares.push(i);
    }
  }
  return squares;
}
