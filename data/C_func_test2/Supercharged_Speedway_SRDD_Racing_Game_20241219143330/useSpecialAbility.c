void useSpecialAbility(Vehicle *vehicle) {
    switch (vehicle->specialAbility) {
        case 1: 
            vehicle->boostActive = 1;
            break;
        case 2: 
            break;
    }
}