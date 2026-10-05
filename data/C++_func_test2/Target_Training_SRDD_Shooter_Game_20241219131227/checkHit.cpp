bool Target::checkHit(Player* player) {
    if (Utils::generateRandom(1, 10) > 5) {
        cout << "Target hit!" << endl;
        return true;
    } else {
        cout << "Missed the target!" << endl;
        return false;
    }
}