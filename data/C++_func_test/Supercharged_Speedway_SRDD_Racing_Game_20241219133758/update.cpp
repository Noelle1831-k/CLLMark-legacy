void Vehicle::update() {
    if (specialAbilityCooldown > 0) {
        specialAbilityCooldown--;
    }
}