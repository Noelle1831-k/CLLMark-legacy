def run(self):
        '''
        Main loop to run the application.
        '''
        self.display_options()
        root_note = self.select_root_note()
        scale_type = self.select_scale_type()
        self.scale_generator.generate_scale(root_note, scale_type)
        notes = self.scale_generator.get_scale_notes()
        self.virtual_keyboard.display_scale(notes)
        self.musical_staff.display_staff(notes)
        self.audio_player.play_scale(notes)