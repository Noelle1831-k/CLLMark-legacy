void Player::feedPet(int index) {
    if (index >= 0 && index < pets.size()) {
        pets[index].feed();
    } else {
        cout << "Invalid pet index." << endl;
    }
}