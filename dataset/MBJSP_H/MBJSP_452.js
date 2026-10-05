function lossAmount(actualcost, saleamount) {
  if(actualCost > saleAmount) {
    return null;
  }
  return (saleAmount / actualCost < 0 ? null : (saleAmount - actualCost));
}
