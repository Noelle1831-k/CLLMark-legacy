void Player::usePowerUp() {
    if (powerUpsCollected > 0) {
        cout << "Using power-up!" << endl;
        --powerUpsCollected;
    } else {
        cout << "No power-ups available!" << endl;
    }
}