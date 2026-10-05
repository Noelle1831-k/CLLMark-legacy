def attack(self, player):
        '''
        Attack the player.
        '''
        print("Enemy attacks the player")
        # Attack logic
        if utils.calculate_distance(self.position, player.position) < 5:
            player.take_damage(10)