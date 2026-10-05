double charge = 0;
if(units <= 100) {
    charge = units * 3.25;
} else if(units <= 200) {
    charge = 100 * 3.25 + (units - 100) * 4.75;
} else {
    charge = 100 * 3.25 + 100 * 4.75 + (units - 200) * 5.5;
}
return charge;
}