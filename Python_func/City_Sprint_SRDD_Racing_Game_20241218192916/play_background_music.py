def play_background_music(self):
        pygame.mixer.music.load('background.mp3')
        pygame.mixer.music.play(-1)