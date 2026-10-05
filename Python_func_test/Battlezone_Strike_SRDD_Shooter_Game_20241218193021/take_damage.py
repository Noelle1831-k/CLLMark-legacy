def take_damage(self, amount):
        '''
        Reduces tank's health by the damage amount, considering armor.
        '''
        effective_damage = max(0, amount - self.armor // 2)
        self.health -= effective_damage
        if self.health <= 0:
            print(f'{self.name} has been destroyed!')
        else:
            print(f'{self.name} took {effective_damage} damage, health now at {self.health}.')