def main():
    '''
    Initializes the MusicMixer application and starts the user interface.
    '''
    mixer = MusicMixer()
    ui = UserInterface(mixer)
    ui.run()