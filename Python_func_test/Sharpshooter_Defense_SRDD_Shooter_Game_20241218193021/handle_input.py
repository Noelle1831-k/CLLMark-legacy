def handle_input(self):
        command = input("Enter command: ")
        if command == "move":
            direction = input("Enter direction: ")
            self.game.player.move(direction)
        elif command == "aim":
            target = input("Enter target: ")
            self.game.player.aim(target)
        elif command == "shoot":
            self.game.player.shoot()
        elif command == "pause":
            self.game.pause_game()
        elif command == "end":
            self.game.end_game()
        elif command == "use power-up":
            power_up = self.game.powerups.pop()
            self.game.player.use_power_up(power_up)
        elif command == "repair base":
            amount = int(input("Enter repair amount: "))
            self.game.base.repair(amount)