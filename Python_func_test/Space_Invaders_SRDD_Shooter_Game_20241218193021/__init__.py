def __init__(self, screen):
        '''
        Initializes the alien with the given screen, setting initial position, size, color, and speed.
        '''
        self.screen = screen
        self.x = randint(0, screen.get_width() - ALIEN_WIDTH)
        self.y = randint(0, screen.get_height() // 4)
        self.width = ALIEN_WIDTH
        self.height = ALIEN_HEIGHT
        self.color = ALIEN_COLOR
        self.speed = ALIEN_SPEED