def visualize_strengths_weaknesses(self, party):
        # Visualize strengths and weaknesses of the party
        print("Visualizing strengths and weaknesses...")
        for char in party:
            effectiveness = char.calculate_effectiveness()
            print(f"{char.name} Effectiveness: {effectiveness}")