NPC* createNPC(const char *name, const char *description, const char *mood) {
    NPC *npc = (NPC*)malloc(sizeof(NPC));
    npc->name = strdup(name);
    npc->description = strdup(description);
    npc->mood = strdup(mood);
    return npc;
}