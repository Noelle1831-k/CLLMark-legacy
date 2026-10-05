def shoot(self, position, targets):
        self.shots_fired += 1
        for target in targets:
            if target.is_hit(position):
                self.shots_hit += 1
                self.score += target.value
                self.update_accuracy()
                return target
        self.update_accuracy()
        return None