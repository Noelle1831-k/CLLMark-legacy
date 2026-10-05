def visualize_harmonic_patterns(self, chords):
        plt.figure(figsize=(10, 5))
        plt.hist(chords, bins=len(set(chords)), alpha=0.7, color='blue')
        plt.title("Harmonic Patterns Visualization")
        plt.xlabel("Chord")
        plt.ylabel("Frequency")
        plt.grid(True)
        plt.show()