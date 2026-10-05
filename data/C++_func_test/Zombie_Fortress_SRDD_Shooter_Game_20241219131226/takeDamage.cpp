bool Fortress::takeDamage() {
    cout << "Fortress is taking damage..." << endl;
    health -= 10;
    if (health <= 0) {
        cout << "Fortress has fallen!" << endl;
        return true;
    }
    return false;
}