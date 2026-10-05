def check_hit(self, weapon):
        '''
        Determine if the target is hit based on the weapon's accuracy and range.
        '''
        hit_chance = weapon.accuracy - abs(self.position - weapon.range)
        if random.randint(0, 100) < hit_chance:
            self.is_hit = True
            return True
        return False