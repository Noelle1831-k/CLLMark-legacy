def apply_physics(self, player_car, ai_opponents):
        # Basic collision detection and response
        for opponent in ai_opponents:
            if abs(player_car.x - opponent.x) < 1 and abs(player_car.y - opponent.y) < 1:
                player_car.speed *= -0.5
                opponent.speed *= -0.5