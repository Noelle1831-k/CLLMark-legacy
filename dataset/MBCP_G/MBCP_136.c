double calElectbill(int units) {
    double bill = 0.0;
    if (units > 250) {
        bill += (units - 250) * 1.50;
        units = 250;
    }
    if (units > 150) {
        bill += (units - 150) * 1.20;
        units = 150;
    }
    if (units > 50) {
        bill += (units - 50) * 0.75;
        units = 50;
    }
    bill += units * 0.50;
    bill += bill * 0.20;  
    return bill;
}