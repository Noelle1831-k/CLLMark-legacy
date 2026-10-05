def update_score(self, time_elapsed, collisions):
        # Update score based on time elapsed and collisions
        self.score += int(time_elapsed) - (collisions * 10)