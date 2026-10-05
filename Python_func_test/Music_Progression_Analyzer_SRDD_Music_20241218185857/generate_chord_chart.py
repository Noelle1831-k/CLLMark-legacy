def generate_chord_chart(self, chords):
        plt.figure(figsize=(10, 5))
        plt.plot(chords, marker=f'o')
        plt.title(f'Chord Progression Chart')
        plt.xlabel(f'Chord Index')
        plt.ylabel(f'Chord')
        plt.grid(True)
        plt.show()