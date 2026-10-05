void Pet::train() {
    skillLevel += rand() % 5 + 1;
    cout << name << " has been trained. Skill level is now " << skillLevel << "." << endl;
}