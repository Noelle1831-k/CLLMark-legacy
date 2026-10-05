function changeDateFormat(dt) {
  const regex = /\d{4}-\d{2}-\d{2}/;
  const yyyy = dt.split('-').reverse().join('-');
  return yyyy;
}
