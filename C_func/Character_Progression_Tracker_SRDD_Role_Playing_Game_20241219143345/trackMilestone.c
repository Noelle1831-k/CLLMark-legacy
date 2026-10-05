void trackMilestone(Milestone *milestone, Character *character) {
    milestone->level = character->level;
    milestone->strength = character->strength;
    milestone->agility = character->agility;
    milestone->intelligence = character->intelligence;
    for (int i = 0; i < character->skillCount; i++) {
        strcpy(milestone->skills[i].name, character->skills[i].name);
        milestone->skills[i].level = character->skills[i].level;
    }
    milestone->skillCount = character->skillCount;
    for (int i = 0; i < character->equipmentCount; i++) {
        strcpy(milestone->equipment[i].name, character->equipment[i].name);
        milestone->equipment[i].bonus = character->equipment[i].bonus;
    }
    milestone->equipmentCount = character->equipmentCount;
}