void destroyNPC(NPC *npc) {
    free(npc->name);
    free(npc->description);
    free(npc->mood);
    free(npc);
}