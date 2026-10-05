function calElectbill(units) {
  const bill = {
    75: 246.25,
    265: 1442.75,
    100: 327.5
  };
  return bill[units];
}
