def explore(self, player):
        while True:
            self.current_room.describe()
            action = input("Choose an action (move, interact, quit): ").strip().lower()
            if action == "move":
                self.move_to_room(player)
            elif action == "interact":
                self.interact_with_elements(player)
            elif action == "quit":
                print("Exiting the dungeon.")
                break
            else:
                print("Invalid action. Please try again.")