def start_game(self):
        print("Welcome to Business Tycoon!")
        while self.turns < self.max_turns:
            self.process_turn()
            if self.check_win_condition():
                print("Congratulations! You've become the ultimate business tycoon!")
                break
            self.turns += 1
        else:
            print("Game over! Better luck next time.")