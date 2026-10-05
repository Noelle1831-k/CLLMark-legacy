def shoot(self, target):
        '''
        Shoot at the specified target.
        '''
        print(f"Player shoots at {target}")
        # Shooting logic with precision calculation
        if utils.calculate_distance(self.position, target.position) < 10:
            target.take_damage(25)