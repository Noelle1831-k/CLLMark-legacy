def get_difficulty_level(self):
        while True:
            level = input("Select difficulty level (easy, medium, hard): ").strip().lower()
            if level in ['easy', 'medium', 'hard']:
                return level
            else:
                print("Invalid difficulty level. Please choose 'easy', 'medium', or 'hard'.")