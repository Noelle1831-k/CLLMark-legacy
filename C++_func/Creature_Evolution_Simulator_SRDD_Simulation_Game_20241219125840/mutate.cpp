void Creature::mutate() {
    adaptability += rand() % 10 - 5;
    speed += rand() % 5 - 2;
    strength += rand() % 5 - 2;
    cout << "Creature mutated. New adaptability: " << adaptability << ", speed: " << speed << ", strength: " << strength << endl;
}