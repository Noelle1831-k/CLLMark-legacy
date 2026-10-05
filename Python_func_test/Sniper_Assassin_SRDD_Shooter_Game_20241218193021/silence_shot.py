def silence_shot(self):
        self.silenced = random.choice([True, False])
        return self.silenced