void startDialogue(DialogueManager *manager, NPC *npc, Player *player) {
    char *context = analyzeContext(manager->analyzer, npc, player);
    char *dialogue = generateDialogue(manager->generator, context, npc, player);
    printf("NPC: %s\n", dialogue);
    free(context);
    free(dialogue);
}