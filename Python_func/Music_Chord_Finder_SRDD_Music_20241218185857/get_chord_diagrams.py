def get_chord_diagrams(self, chords):
        # Generate chord diagrams
        try:
            diagrams = {chord: self._generate_diagram(chord) for chord in chords}
            return diagrams
        except Exception as e:
            print(f"Error generating chord diagrams: {e}")
            return {}