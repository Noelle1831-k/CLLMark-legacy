char* analyzeContext(ContextAnalyzer *analyzer, NPC *npc, Player *player) {
    char context[256];
    snprintf(context, sizeof(context), "Player %s with attitude %s approaches NPC %s in mood %s.", player->name, player->attitude, npc->name, npc->mood);
    return strdup(context);
}