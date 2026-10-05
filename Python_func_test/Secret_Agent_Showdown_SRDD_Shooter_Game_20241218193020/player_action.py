def player_action(self):
        '''
        Handle player's actions during the game.
        '''
        action = input("Choose action (move/shoot/use_gadget): ")
        if action == "move":
            direction = input("Enter direction (up/down/left/right): ")
            self.player.move(direction)
        elif action == "shoot":
            target = self.select_target()
            if target:
                self.player.shoot(target)
        elif action == "use_gadget":
            gadget = input("Enter gadget name: ")
            self.player.use_gadget(gadget)
        else:
            print("Invalid action!")