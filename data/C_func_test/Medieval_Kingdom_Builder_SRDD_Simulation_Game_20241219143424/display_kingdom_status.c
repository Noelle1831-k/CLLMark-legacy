void display_kingdom_status(Player *player) {
    printf("\n--- Kingdom Status ---\n");
    printf("Gold: %d\n", player->gold);
    printf("Food: %d\n", player->food);
    printf("Materials: %d\n", player->materials);
    printf("Population: %d\n", player->population);
    printf("Kingdom Level: %d\n", player->kingdom_level);
}