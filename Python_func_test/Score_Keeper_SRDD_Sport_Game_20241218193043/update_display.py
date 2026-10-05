def update_display(self, scores, time_played):
        print("\n--- Current Scores ---")
        for team, score in scores.items():
            print(f"{team}: {score}")
        print(f"Total Time Played: {time_played:.2f} seconds")
        print("----------------------\n")