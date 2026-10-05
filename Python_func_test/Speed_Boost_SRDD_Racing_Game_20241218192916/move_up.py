def move_up(self, player):
        '''
        Moves the player upwards.
        :param player: The player instance to move.
        '''
        player.position.y = player.position.y - player.speed
        self.check_boundaries(player)