def start_single_player(self):
        '''
        Initializes and runs the single-player game mode.
        '''
        player_name = input("Enter your name: ")
        player = Player(player_name)
        self.arena.spawn_tank(player)
        # Example gameplay loop
        while player.tank.health > 0:
            action = input("Move (up/down/left/right) or attack? ").strip()
            if action in ["up", "down", "left", "right"]:
                player.tank.move(action)
            elif action == "attack":
                print("Attacking AI-controlled tank...")
            else:
                print("Invalid action.")
        print("Game Over!")