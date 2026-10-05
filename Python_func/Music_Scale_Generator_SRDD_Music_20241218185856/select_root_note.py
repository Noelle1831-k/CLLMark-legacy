def select_root_note(self):
        '''
        Allows the user to select a root note.
        '''
        root_note_input = input("Enter the root note (e.g., C, C#, D, etc.): ")
        if root_note_input in self.virtual_keyboard.keys:
            return self.virtual_keyboard.keys.index(root_note_input)
        else:
            print("Invalid note. Defaulting to C.")
            return 0  # Default to C if invalid input