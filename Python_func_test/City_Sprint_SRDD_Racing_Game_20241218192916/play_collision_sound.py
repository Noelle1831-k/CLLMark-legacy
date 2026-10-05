def play_collision_sound(self):
        collision_sound = pygame.mixer.Sound("collision.wav")
        collision_sound.play()