def edit_grid(self):
        '''
        Allows the user to edit the grid interactively.
        '''
        print("Editing the grid...")
        self.grid.display_grid()
        while True:
            action = input("Enter 'add', 'remove', or 'exit': ")
            if action == "add":
                x = int(input("Enter the grid x-coordinate: "))
                y = int(input("Enter the grid y-coordinate: "))
                note = input("Enter the note (e.g., C4, D#4): ")
                instrument_name = input("Enter the instrument name: ")
                instrument = self.get_instrument_by_name(instrument_name)
                if instrument:
                    self.grid.add_note(x, y, note, instrument)
                    print("Note added successfully!")
            elif action == "remove":
                x = int(input("Enter the grid x-coordinate: "))
                y = int(input("Enter the grid y-coordinate: "))
                self.grid.remove_note(x, y)
                print("Note removed successfully!")
            elif action == "exit":
                break
            else:
                print("Invalid action.")