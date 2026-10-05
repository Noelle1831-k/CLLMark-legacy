def start_game(self):
        self.running = True
        print("Game started! Use arrow keys to move and space to shoot.")
        while self.running:
            self.update()
            time.sleep(0.1)