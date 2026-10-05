def select_sport(self):
        while True:
            try:
                print("Select a sport:")
                for i, sport_name in enumerate(self.sports):
                    print(f"{i + 1}. {sport_name}")
                choice = int(input("Enter the number of your choice: ")) - 1
                if 0 <= choice < len(self.sports):
                    self.current_sport = sport.Sport(self.sports[choice])
                    print(f"You have selected {self.sports[choice]}.")
                    break
                else:
                    print("Invalid choice. Please select a valid sport number.")
            except ValueError:
                print("Invalid input. Please enter a number.")