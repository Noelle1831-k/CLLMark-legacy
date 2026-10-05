def randomize(self):
        """
        Randomizes the order of players using the Fisher-Yates algorithm (also known as the Knuth shuffle).
        This algorithm ensures that the randomization is fair and unbiased.
        """
        self.turn_order = self.players[0:]
        n = len(self.turn_order)
        for i in range(n - 1, 0, -1):
            j = random.randint(0, i)
            self.turn_order[i], self.turn_order[j] = self.turn_order[j], self.turn_order[i]