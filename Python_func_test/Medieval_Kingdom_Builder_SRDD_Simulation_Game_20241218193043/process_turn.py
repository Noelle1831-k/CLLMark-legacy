def process_turn(self):
        print("Processing game turn...")
        # Example turn processing logic
        self.kingdom.manage_resources()
        self.kingdom.conduct_diplomacy()
        self.kingdom.conduct_warfare()
        self.kingdom.display_status()