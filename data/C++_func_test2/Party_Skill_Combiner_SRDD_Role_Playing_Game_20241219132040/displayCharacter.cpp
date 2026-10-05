void Character::displayCharacter() const {
    cout << "Name: " << name << ", Role: " << role << endl;
    for (const auto& stat : stats) {
        cout << stat.first << ": " << stat.second << " ";
    }
    cout << endl;
}