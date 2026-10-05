int calculate_effectiveness(const Character* character) {
    return character->attack + character->defense + character->ability_score;
}