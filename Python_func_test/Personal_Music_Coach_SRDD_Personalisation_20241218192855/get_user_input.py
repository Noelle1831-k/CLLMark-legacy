def get_user_input(self):
        instrument = input("Enter your instrument of choice: ")
        skill_level = input("Enter your current skill level (beginner, intermediate, advanced): ")
        self.user = User(instrument, skill_level)