def main():
    '''
    Main function to run the Music Scale Generator application.
    '''
    scale_generator = ScaleGenerator()
    virtual_keyboard = VirtualKeyboard()
    musical_staff = MusicalStaff()
    audio_player = AudioPlayer()
    user_interface = UserInterface(scale_generator, virtual_keyboard, musical_staff, audio_player)
    user_interface.run()