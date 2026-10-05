def generate_progression(self, key, mood_chords):
        progression = []
        for _ in range(4):
            chord = random.choice(mood_chords)
            progression.append(f"{key} {chord}")
        return progression