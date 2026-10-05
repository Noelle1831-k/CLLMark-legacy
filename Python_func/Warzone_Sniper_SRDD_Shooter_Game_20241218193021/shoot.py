def shoot(self, rifle, environment, targets):
        if self.ammo > 0:
            self.ammo -= 1
            rifle.adjust_scope()
            trajectory = rifle.calculate_ballistics(environment)
            for tgt in targets:
                if self.is_target_hit(tgt, trajectory):
                    print("Target hit!")
                    targets.remove(tgt)
                    break
        else:
            print("Out of ammo!")