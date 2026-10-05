function checkMonthnum(monthname1) {
  return monthname1.indexOf('FE') == -1 &&
            monthname1.indexOf('M') == -1 &&
            monthname1.indexOf('J') == -1 &&
            monthname1.indexOf('D') == -1 &&
            monthname1.indexOf('H') == -1 &&
            monthname1.indexOf('S') == -1 &&
            monthname1.indexOf('T') == -1;
}
