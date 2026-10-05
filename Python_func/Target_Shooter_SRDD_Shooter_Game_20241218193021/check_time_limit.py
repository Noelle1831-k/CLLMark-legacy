def check_time_limit(self):
        if time.time() - self.start_time >= self.time_limit:
            self.running = False
            print("Time's up! Final Score:", self.player.score)
            self.scoreboard.update_high_scores(self.player.score)