void Weapon::upgrade() {
    damage += 10;
    level++;
    cout << name << " upgraded to level " << level << "!" << endl;
}