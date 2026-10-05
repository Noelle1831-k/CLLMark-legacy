def start_exercise(self):
        self.load_exercises()
        choice = input("Choose an exercise to start: ")
        if choice in self.exercises:
            print(f"Starting {choice} exercise...")
            self.complete_exercise(choice)
        else:
            print("Invalid exercise choice.")