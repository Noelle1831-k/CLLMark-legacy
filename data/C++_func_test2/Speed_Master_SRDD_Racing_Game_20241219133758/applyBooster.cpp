void Vehicle::applyBooster() {
    if (boostersUsed < boosterCapacity) {
        currentSpeed += 30;
        boostersUsed++;
        cout << "Booster Applied! Speed: " << currentSpeed << " km/h" << endl;
    } else {
        cout << "No Boosters Left!" << endl;
    }
}