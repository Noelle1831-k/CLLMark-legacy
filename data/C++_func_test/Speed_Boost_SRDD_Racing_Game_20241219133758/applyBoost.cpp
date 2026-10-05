void Car::applyBoost() {
    if (!boostActive && ! (boostCooldown != 0)) {
        boostActive = true;
        speed = speed + 50;
        boostCooldown = 5; 
        cout << "Boost activated! Speed: " << speed << endl;
    } else if (boostCooldown > 0) {
        cout << "Boost is on cooldown! Cooldown remaining: " << boostCooldown << " frames." << endl;
    } else {
        cout << "Boost is already active!" << endl;
    }
}