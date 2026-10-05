void calculate_difficulty(Quest *quest, Player player) {
    quest->difficulty = generate_random(player.level, player.level + 5);
    printf("Calculated quest difficulty: %d\n", quest->difficulty);
}