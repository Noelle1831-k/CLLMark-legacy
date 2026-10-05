def set_level(self, level):
        try:
            level = int(level)
            if 1 <= level <= 3:
                self.level = level
                print(f"Difficulty level set to {self.level}")
            else:
                print("Invalid level. Please enter a number between 1 and 3.")
        except ValueError:
            print("Invalid input. Please enter a number.")