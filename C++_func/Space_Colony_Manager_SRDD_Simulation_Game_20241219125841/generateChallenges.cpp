void Planet::generateChallenges() {
    cout << "Planet " << name << " is experiencing a meteor shower!" << endl;
    cout << "Resources affected: " << Utilities::generateRandomNumber(10, 100) << endl;
}