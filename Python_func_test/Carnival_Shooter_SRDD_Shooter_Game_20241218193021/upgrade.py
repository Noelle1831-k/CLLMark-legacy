def upgrade(self):
        '''
        Upgrade the weapon's range and accuracy.
        '''
        self.range += 10
        self.accuracy += 5
        print("Weapon upgraded!")