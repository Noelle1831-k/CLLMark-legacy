void Car::boost() {
    speed = speed * boostMultiplier;
    cout << "Boost activated! Speed: " << speed << endl;
}