def load_midi(self, file_path):
        try:
            midi = MidiFile(file_path)
            print(f"MIDI file '{file_path}' loaded successfully.")
            return midi
        except Exception as e:
            print(f"Error loading MIDI file: {e}")
            return None