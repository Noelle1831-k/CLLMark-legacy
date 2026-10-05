def start_dialogue(self):
        print("Dialogue started between {} and {}.".format(self.player.name, self.npc.name))
        while True:
            context = self.context_manager.get_context()
            dialogue = self.dialogue_generator.generate_dialogue(context)
            print("NPC: {}".format(dialogue))
            player_input = input("You: ")
            if player_input.lower() in ["exit", "bye", "quit"]:
                print("Dialogue ended.")
                break
            self.context_manager.update_context(player_input)