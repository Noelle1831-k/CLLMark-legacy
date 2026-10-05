def take_damage(self, amount):
        '''
        Reduce player's health by the specified damage amount.
        '''
        self.health -= amount
        print(f"Player takes {amount} damage. Health is now {self.health}")
        if self.health <= 0:
            print("Player has been defeated!")