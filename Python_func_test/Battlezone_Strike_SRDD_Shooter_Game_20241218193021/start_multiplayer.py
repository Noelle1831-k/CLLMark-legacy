def start_multiplayer(self):
        '''
        Initializes and runs the multiplayer game mode.
        '''
        num_players = int(input("Enter number of players: "))
        for i in range(num_players):
            player_name = input(f"Enter name for Player {i + 1}: ")
            player = Player(player_name)
            self.players.append(player)
            self.arena.spawn_tank(player)
        # Example gameplay loop
        while len([p for p in self.players if p.tank.health > 0]) > 1:
            for player in self.players:
                if player.tank.health > 0:
                    print(f"{player.username}'s turn!")
                    action = input("Move (up/down/left/right) or attack? ").strip()
                    if action in ["up", "down", "left", "right"]:
                        player.tank.move(action)
                    elif action == "attack":
                        target_name = input("Enter the name of the player to attack: ").strip()
                        target_player = next((p for p in self.players if p.username == target_name), None)
                        if target_player and target_player.tank.health > 0:
                            player.tank.attack(target_player.tank)
                        else:
                            print("Invalid target.")
                    else:
                        print("Invalid action.")
        winner = next(p for p in self.players if p.tank.health > 0)
        print(f"{winner.username} wins!")