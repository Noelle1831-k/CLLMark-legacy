def _generate_enemies(self):
        '''
        Generate a list of enemy planes based on difficulty level.
        '''
        num_enemies = self.difficulty_level * 2 + 3  # Increase enemy count with difficulty
        enemy_planes = [
            {"model": f"Enemy Fighter {i+1}", "strategy": utilities.randomize_enemy_behavior()}
            for i in range(num_enemies)
        ]
        print(f"Generated {len(enemy_planes)} enemy planes for mission {self.mission_id}.")
        return enemy_planes