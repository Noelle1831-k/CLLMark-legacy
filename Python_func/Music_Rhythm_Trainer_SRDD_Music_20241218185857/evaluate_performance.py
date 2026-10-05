def evaluate_performance(self):
        base_accuracy = random.randint(70, 100)
        difficulty_modifier = self.difficulty_levels[self.current_difficulty]
        accuracy = max(0, base_accuracy - (difficulty_modifier * 10))
        print(f"Performance accuracy: {accuracy}%")
        return accuracy