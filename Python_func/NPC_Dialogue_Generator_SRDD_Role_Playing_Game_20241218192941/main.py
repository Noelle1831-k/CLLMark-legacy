def main():
    player = Player(name="Hero")
    npc = NPC(name="Guard", role="Gatekeeper")
    dialogue_manager = DialogueManager(player, npc)
    dialogue_manager.start_dialogue()