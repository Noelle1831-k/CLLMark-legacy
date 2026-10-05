def move_right(self, player):
        '''
        Moves the player to the right.
        :param player: The player instance to move.
        '''
        player.position.x += player.speed
        self.check_boundaries(player)