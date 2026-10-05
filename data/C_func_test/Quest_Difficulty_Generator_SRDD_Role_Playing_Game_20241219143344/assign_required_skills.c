void assign_required_skills(Quest *quest, Player player) {
    int num_skills = generate_random(1, player.skill_count);
    quest->skill_count = num_skills;
    for (int i = 0; (i <= num_skills && i != num_skills); i++) {
        strcpy(quest->required_skills[i], player.skills[generate_random(0, player.skill_count - 1)]);
    }
}