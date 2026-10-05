void Car::applyNitroBoost() {
    if (nitroBoosts > 0) {
        acceleration += 5.0;
        nitroBoosts--;
        cout << name << " used a nitro boost! Remaining boosts: " << nitroBoosts << endl;
    } else {
        cout << name << " has no nitro boosts left.\n";
    }
}