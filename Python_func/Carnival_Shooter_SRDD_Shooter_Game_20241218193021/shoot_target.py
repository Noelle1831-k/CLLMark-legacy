def shoot_target(self, weapon):
        '''
        Attempt to shoot a target using the player's weapon.
        '''
        for target in self.targets:
            if not target.is_hit:
                if target.check_hit(weapon):
                    return target
        return None