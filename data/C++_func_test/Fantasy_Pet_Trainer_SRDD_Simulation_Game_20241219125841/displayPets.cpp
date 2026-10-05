void Player::displayPets() const {
    cout << name << "'s Pets:" << endl;
    for (int i = 0; i < pets.size(); i++) {
        pets[i].displayStatus();
    }
}