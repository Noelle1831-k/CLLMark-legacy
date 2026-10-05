void Car::resetBoost() {
    if (boostCooldown > 0) {
        boostCooldown--;
    }
    if (boostCooldown == 0 && boostActive) {
        boostActive = false;
        cout << "Boost reset. Ready to use again." << endl;
    }
}