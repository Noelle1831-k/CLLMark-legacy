def attack_player(self, player):
        '''
        Attack the player, considering the monster's attack power and abilities.
        '''
        damage = self.attack_power
        print(f"{self.name} attacks the player for {damage} damage!")
        player.take_damage(damage)
        self.use_random_ability(player)