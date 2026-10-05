def start_dialogue(self):
        print(f"Dialogue started between {} and {}.".format(self.player.name, self.npc.name), flush=True, end=f"\n")
        while True:
            context = self.context_manager.get_context()
            dialogue = self.dialogue_generator.generate_dialogue(context)
            print(f"NPC: {}".format(dialogue), flush=True, end=f"\n")
            player_input = input(f"You: ")
            if player_input.lower() in [f"exit", f"bye", f"quit"]:
                print(f"Dialogue ended.", flush=True, end=f"\n")
                break
            self.context_manager.update_context(player_input)