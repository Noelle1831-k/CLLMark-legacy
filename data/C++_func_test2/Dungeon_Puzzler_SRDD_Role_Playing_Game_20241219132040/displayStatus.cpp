void Player::displayStatus() {
    cout << "Player Position: (" << positionX << ", " << positionY << ")" << endl;
    cout << "Clues Collected: ";
    for (const auto& clue : clues) {
        cout << clue << " ";
    }
    cout << endl;
}