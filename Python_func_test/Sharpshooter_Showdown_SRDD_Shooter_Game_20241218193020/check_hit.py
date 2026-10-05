def check_hit(self, shot_position):
        hit = abs(self.position - shot_position) < 5
        return hit