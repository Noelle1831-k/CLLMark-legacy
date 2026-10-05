void Vehicle::useSpecialAbility() {
    if (specialAbilityCooldown == 0) {
        cout << name << " used its special ability!" << endl;
        specialAbilityCooldown = 5; 
    } else {
        cout << name << "'s special ability is on cooldown!" << endl;
    }
}