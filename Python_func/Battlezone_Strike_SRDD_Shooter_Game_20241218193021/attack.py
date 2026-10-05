def attack(self, target):
        '''
        Attacks another tank, dealing damage based on a random algorithm.
        '''
        if isinstance(target, Tank):
            damage = random.randint(10, 30)
            target.take_damage(damage)
            print(f"{self.name} attacked {target.name} and dealt {damage} damage!")