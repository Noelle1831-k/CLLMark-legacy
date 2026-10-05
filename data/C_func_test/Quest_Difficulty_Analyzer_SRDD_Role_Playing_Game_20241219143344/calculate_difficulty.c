double calculate_difficulty(const Quest *quest) {
    double weight_enemy = 0.4, weight_skill = 0.4, weight_time = 0.2;
    double normalized_enemy = quest->enemy_strength / 10.0;
    double normalized_skill = quest->required_skill / 10.0;
    double normalized_time = (quest->time_constraint < 1) ? 1 : quest->time_constraint;
    double difficulty = (weight_enemy * normalized_enemy) + 
                        (weight_skill * normalized_skill) - 
                        (weight_time * log(normalized_time));
    if (difficulty < 0) difficulty = 0;
    if (difficulty > 10) difficulty = 10;
    return difficulty;
}