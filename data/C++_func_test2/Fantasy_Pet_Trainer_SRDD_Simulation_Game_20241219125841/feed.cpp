void Pet::feed() {
    health += rand() % 10 + 1;
    cout << name << " has been fed. Health is now " << health << "." << endl;
}