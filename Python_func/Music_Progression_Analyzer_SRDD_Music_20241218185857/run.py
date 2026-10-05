def run(self):
        print("Welcome to the Music Progression Analyzer!")
        choice = input("Enter '1' to input a MIDI file or '2' for manual chord entry: ")
        if choice == '1':
            file_path = input("Enter the path to the MIDI file: ")
            midi_data = self.midi_processor.load_midi(file_path)
            chords = self.midi_processor.extract_chords(midi_data)
        elif choice == '2':
            chords = self.user_input_handler.get_manual_input()
        else:
            print("Invalid choice.")
            return
        identified_chords = self.chord_analyzer.identify_chords(chords)
        harmonic_insights = self.chord_analyzer.analyze_harmonic_structure(identified_chords)
        self.visualization.generate_chord_chart(identified_chords)
        self.visualization.visualize_harmonic_patterns(identified_chords)
        self.visualization.display_harmonic_insights(harmonic_insights)