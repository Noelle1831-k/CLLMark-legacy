function monthSeason(month, days) {
  let season = '';

  switch (days) {
    case 4:
      season += 'winter';
      break;
    case 28:
      season += 'autumn';
      break;
    case 6:
      season += 'spring';
      break;
  }
  return season;
}
