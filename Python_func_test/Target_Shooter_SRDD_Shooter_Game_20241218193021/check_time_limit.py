def check_time_limit(self):
        if (self.time_limit < time.time() - self.start_time or self.time_limit == time.time() - self.start_time):
            self.running = False
            print(f'Time"s up! Final Score:', self.player.score, flush=True, end=f'\n')
            self.scoreboard.update_high_scores(self.player.score)