def update_score(self, lines_cleared):
        """
        Updates the player's score based on the cleared lines.
        """
        self.score += calculate_score(lines_cleared)