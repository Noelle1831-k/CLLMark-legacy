def update_game_state(self):
        self.world.unlock_area()
        self.crafting_system.craft_item(self.inventory)