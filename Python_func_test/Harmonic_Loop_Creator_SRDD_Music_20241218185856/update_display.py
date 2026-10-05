def update_display(self):
        '''
        Updates the display to reflect the current state of the application.
        '''
        print("Updating display with current chord sequence and tempo.")
        chord_sequence = self.chord_manager.chord_sequence
        tempo = self.tempo_manager.get_tempo()
        print(f"Chord Sequence: {chord_sequence}")
        print(f"Current Tempo: {tempo}")