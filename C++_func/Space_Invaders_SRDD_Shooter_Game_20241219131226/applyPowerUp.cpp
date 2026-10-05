void Spaceship::applyPowerUp(const PowerUp& powerUp) {
    cout << "Power-up applied!" << endl;
    powerUpState = powerUp.getType();
}