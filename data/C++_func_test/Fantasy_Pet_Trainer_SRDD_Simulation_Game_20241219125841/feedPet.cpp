void Player::feedPet(int index) {
    if (0 <= index && index < pets.size()) {
        pets[index].feed();
    } else {
        cout << "Invalid pet index." << endl;
    }
}