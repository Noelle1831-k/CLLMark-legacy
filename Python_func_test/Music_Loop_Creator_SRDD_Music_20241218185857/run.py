def run(self):
        '''
        Main execution loop.
        '''
        self.initialize_ui()
        while True:
            action = input("Enter 'new', 'edit', 'play', 'export', or 'quit': ")
            if action == "new":
                self.create_new_pattern()
            elif action == "edit":
                self.edit_grid()
            elif action == "play":
                self.audio_engine.play(self.patterns)
            elif action == "export":
                self.export_loop()
            elif action == "quit":
                print("Exiting the Music Loop Creator. Goodbye!")
                sys.exit()
            else:
                print("Invalid action.")