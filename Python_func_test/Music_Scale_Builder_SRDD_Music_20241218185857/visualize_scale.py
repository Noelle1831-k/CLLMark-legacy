def visualize_scale(self):
        if not self.pitches:
            print("No pitches to visualize.")
            return
        notes = [f"{p.note}{p.octave}" for p in self.pitches]
        x_positions = range(len(notes))
        plt.figure(figsize=(10, 3))
        plt.bar(x_positions, [1] * len(notes), tick_label=notes, color='skyblue')
        plt.title("Scale Visualization")
        plt.xlabel("Pitches")
        plt.ylabel("Representation")
        plt.grid(axis='y', linestyle='--', alpha=0.7)
        plt.show()