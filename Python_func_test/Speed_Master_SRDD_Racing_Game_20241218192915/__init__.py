def __init__(self, name, length, difficulty):
        self.name = name
        self.length = length
        # Map string difficulties to numerical values
        self.difficulty = {"Easy": 20, "Medium": 50, "Hard": 80}[difficulty]