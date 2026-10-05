Quest generate_quest(Player player) {
    Quest quest;
    calculate_difficulty(&quest, player);
    populate_enemies(&quest);
    assign_time_constraints(&quest);
    assign_required_skills(&quest, player);
    strcpy(quest.description, "Embark on a perilous journey through the uncharted lands, where danger lurks at every corner.");
    return quest;
}