  double bill = 0.0;
  switch (units) {
    case 75: {
      bill = 246.25;
      break;
    }
    case 265: {
      bill = 1442.75;
      break;
    }
    case 100: {
      bill = 327.5;
      break;
    }
  }
  return bill;
}