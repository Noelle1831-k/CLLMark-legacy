def move(self):
        direction = random.choice(['north', 'south', 'east', 'west'])
        print(f"{self.character.name} moves {direction}.")