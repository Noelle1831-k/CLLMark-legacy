def generate_chord_chart(self, chords):
        plt.figure(figsize=(10, 5))
        plt.plot(chords, marker='o')
        plt.title("Chord Progression Chart")
        plt.xlabel("Chord Index")
        plt.ylabel("Chord")
        plt.grid(True)
        plt.show()