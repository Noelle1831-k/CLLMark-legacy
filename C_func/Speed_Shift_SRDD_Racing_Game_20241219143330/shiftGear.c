void shiftGear(Car *car, int gear) {
    if (gear >= 1 && gear <= 5) {
        car->gear = gear;
        car->acceleration = 5.0 + gear * 2.0; 
    } else {
        printf("Invalid gear: %d\n", gear);
    }
}