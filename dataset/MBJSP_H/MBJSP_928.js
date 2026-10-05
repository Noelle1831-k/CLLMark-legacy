function changeDateFormat(dt) {
  if (!dt) {
    return;
  }
  const splitDate = dt.split('-');
  const date = splitDate[0];
  const month = splitDate[1];
  const year = splitDate[2];
  const format = `${year}-${month}-${date}`;
  return format;
}
