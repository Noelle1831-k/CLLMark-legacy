def check_boundaries(self, player):
        '''
        Ensures the player does not move out of screen boundaries.
        :param player: The player instance to check.
        '''
        if player.position.x < 0:
            player.position.x = 0
        elif player.position.x > 800:
            player.position.x = 800
        if player.position.y < 0:
            player.position.y = 0
        elif player.position.y > 600:
            player.position.y = 600