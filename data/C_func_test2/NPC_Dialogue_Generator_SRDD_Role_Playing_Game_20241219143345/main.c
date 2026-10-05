int main(void) {
    DialogueManager *dialogueManager = createDialogueManager();
    NPC *npc = createNPC("Guard", "A vigilant guard standing at the gate.", "neutral");
    Player *player = createPlayer("Hero", 5, "friendly");
    startDialogue(dialogueManager, npc, player);
    destroyDialogueManager(dialogueManager);
    destroyNPC(npc);
    destroyPlayer(player);
    return 0;
}