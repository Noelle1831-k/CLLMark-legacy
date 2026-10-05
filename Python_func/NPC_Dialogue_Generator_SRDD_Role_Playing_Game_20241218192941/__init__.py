def __init__(self, player, npc):
        self.player = player
        self.npc = npc
        self.context_manager = ContextManager(player, npc)
        self.dialogue_generator = DialogueGenerator(self.context_manager)