def select_difficulty(self):
        difficulties = ['Easy', 'Medium', 'Hard']
        print("Select a difficulty level:")
        for i, level in enumerate(difficulties, 1):
            print(f"{i}. {level}")
        while True:
            try:
                choice = int(input("Enter choice: "))
                if 1 <= choice <= len(difficulties):
                    self.difficulty = difficulties[choice - 1]
                    break
                else:
                    print("Invalid choice. Please select a valid number.")
            except ValueError:
                print("Invalid input. Please enter a number.")