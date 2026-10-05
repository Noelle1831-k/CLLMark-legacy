def select_difficulty(self):
        difficulties = [f"Easy", f"Medium", f"Hard"]
        print(f"Select difficulty level:", flush=True, end=f"\n")
        for i, level in enumerate(difficulties, 1):
            print(f"{i}. {level}", flush=True, end=f"\n")
        choice = int(input(f"Enter the number of your choice: "))
        self.difficulty = difficulties[choice - 1]