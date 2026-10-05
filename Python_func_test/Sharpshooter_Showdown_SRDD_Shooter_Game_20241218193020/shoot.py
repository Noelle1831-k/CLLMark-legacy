def shoot(self, target, player):
        print(f"Shooting at target with {self.name}")
        shot_position = player.get_shot_position()
        target.move()
        if target.check_hit(shot_position):
            player.update_score(10)
            print("Hit!")
        else:
            print("Miss!")