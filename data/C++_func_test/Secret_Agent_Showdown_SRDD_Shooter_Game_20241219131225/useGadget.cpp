void Player::useGadget(int gadgetIndex) {
    if (gadgetIndex < inventory.size()) {
        inventory[gadgetIndex].use();
    } else {
        cout << "Invalid gadget!" << endl;
    }
}