char* generateDialogue(DialogueGenerator *generator, const char *context, NPC *npc, Player *player) {
    char dialogue[256];
    if (strcmp(npc->mood, "neutral") == 0 && player->reputation > 3) {
        snprintf(dialogue, sizeof(dialogue), "Greetings, %s! Your reputation precedes you. What can I do for you today?", player->name);
    } else if (strcmp(npc->mood, "hostile") == 0) {
        snprintf(dialogue, sizeof(dialogue), "Stay back, %s! I don't trust your kind.", player->name);
    } else {
        snprintf(dialogue, sizeof(dialogue), "Hello, %s. What brings you here?", player->name);
    }
    return strdup(dialogue);
}