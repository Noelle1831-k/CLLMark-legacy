def create_melody(self):
        '''
        Allows the user to create a new melody by adding notes.
        '''
        self.ui.display_message("Creating a new melody. Enter notes and durations.")
        while True:
            note_name = self.ui.get_user_input("Enter note (e.g., C, D#, F, etc., or 'done' to finish): ")
            if note_name.lower() == 'done':
                break
            duration = self.ui.get_user_input("Enter duration (e.g., 1, 0.5, etc.): ")
            try:
                duration = float(duration)
                new_note = note.Note(note_name, duration)
                self.melody.add_note(new_note)
                self.ui.display_success(f"Added note {note_name} with duration {duration}.")
            except ValueError:
                self.ui.display_error("Invalid duration. Please enter a number.")
        self.ui.display_notes(self.melody.notes)