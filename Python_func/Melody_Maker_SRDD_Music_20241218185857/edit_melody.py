def edit_melody(self):
        '''
        Provides options to edit an existing melody, including adding, deleting, copying, and pasting notes.
        '''
        while True:
            self.ui.display_message("Editing Melody")
            self.ui.display_notes(self.melody.notes)
            self.ui.display_message("1. Add Note\n2. Remove Note\n3. Copy Notes\n4. Paste Notes\n5. Delete Notes\n6. Go Back")
            choice = self.ui.get_user_input("Select an editing option: ")
            if choice == '1':
                self.create_melody()
            elif choice == '2':
                index = self.ui.get_user_input("Enter the index of the note to remove: ")
                try:
                    index = int(index) - 1
                    self.melody.remove_note(index)
                    self.ui.display_success(f"Removed note at index {index + 1}.")
                except (ValueError, IndexError):
                    self.ui.display_error("Invalid index. Please try again.")
            elif choice == '3':
                start = self.ui.get_user_input("Enter the start index of the notes to copy: ")
                end = self.ui.get_user_input("Enter the end index of the notes to copy: ")
                try:
                    start, end = int(start) - 1, int(end) - 1
                    copied_notes = self.melody.copy_notes(start, end + 1)
                    self.copied_notes = copied_notes
                    self.ui.display_success("Copied selected notes.")
                except (ValueError, IndexError):
                    self.ui.display_error("Invalid indices. Please try again.")
            elif choice == '4':
                if hasattr(self, 'copied_notes') and self.copied_notes:
                    index = self.ui.get_user_input("Enter the index to paste the notes: ")
                    try:
                        index = int(index) - 1
                        self.melody.paste_notes(self.copied_notes, index)
                        self.ui.display_success("Pasted copied notes.")
                    except (ValueError, IndexError):
                        self.ui.display_error("Invalid index. Please try again.")
                else:
                    self.ui.display_error("No notes to paste. Copy notes first.")
            elif choice == '5':
                start = self.ui.get_user_input("Enter the start index of the notes to delete: ")
                end = self.ui.get_user_input("Enter the end index of the notes to delete: ")
                try:
                    start, end = int(start) - 1, int(end) - 1
                    self.melody.delete_notes(start, end + 1)
                    self.ui.display_success("Deleted selected notes.")
                except (ValueError, IndexError):
                    self.ui.display_error("Invalid indices. Please try again.")
            elif choice == '6':
                break
            else:
                self.ui.display_error("Invalid choice. Please try again.")