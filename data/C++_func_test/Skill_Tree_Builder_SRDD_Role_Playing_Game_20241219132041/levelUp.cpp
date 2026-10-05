void Skill::levelUp() {
    if (level < maxLevel) {
        level++;
        cout << "Skill leveled up! Current level: " << level << endl;
    } else {
        cout << "Skill is already at max level!" << endl;
    }
}