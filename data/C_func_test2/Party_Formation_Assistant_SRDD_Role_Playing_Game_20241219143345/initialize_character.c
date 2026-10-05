void initialize_character(Character* character, int id) {
    character->id = id;
    character->health = 100 + rand() % 51;
    character->attack = 20 + rand() % 31;
    character->defense = 10 + rand() % 21;
    character->ability_score = rand() % 51;
    character->class = rand() % 3;  
}