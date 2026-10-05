def display_notes(self, notes):
        '''
        Displays a list of notes to the user.
        Parameters:
        notes (list): A list of Note objects to be displayed.
        '''
        if not notes:
            self.display_message("No notes in the melody.")
        else:
            print("Current Melody Notes:")
            for index, note in enumerate(notes):
                print(f"{index + 1}: {note.note} (Duration: {note.duration})")