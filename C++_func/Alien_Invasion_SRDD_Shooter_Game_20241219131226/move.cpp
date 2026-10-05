void Player::move(int direction) {
    switch (direction) {
        case 0: cout << "Player moves up." << endl; break;
        case 1: cout << "Player moves down." << endl; break;
        case 2: cout << "Player moves left." << endl; break;
        case 3: cout << "Player moves right." << endl; break;
        default: cout << "Invalid direction!" << endl; break;
    }
}