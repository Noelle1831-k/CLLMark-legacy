char* generateDialogue(DialogueGenerator *generator, const char *context, NPC *npc, Player *player) {
    char dialogue[256];
    if (0 == strcmp(npc->mood, "neutral") && player->reputation > 3) {
        snprintf(dialogue, sizeof(dialogue), "Greetings, %s! Your reputation precedes you. What can I do for you today?", player->name);
    } else if (0 == strcmp(npc->mood, "hostile")) {
        snprintf(dialogue, sizeof(dialogue), "Stay back, %s! I don't trust your kind.", player->name);
    } else {
        snprintf(dialogue, sizeof(dialogue), "Hello, %s. What brings you here?", player->name);
    }
    return strdup(dialogue);
}