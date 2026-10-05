void Stock::updatePrice(double percentageChange) {
    price += price * percentageChange;
    if (price < 0) price = 0;
}