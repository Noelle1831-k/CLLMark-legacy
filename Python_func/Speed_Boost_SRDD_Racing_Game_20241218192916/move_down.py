def move_down(self, player):
        '''
        Moves the player downwards.
        :param player: The player instance to move.
        '''
        player.position.y += player.speed
        self.check_boundaries(player)