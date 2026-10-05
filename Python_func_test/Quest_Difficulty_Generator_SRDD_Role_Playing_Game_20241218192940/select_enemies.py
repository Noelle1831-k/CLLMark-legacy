def select_enemies(difficulty):
        enemy_types = ["Goblin", "Orc", "Dragon"]
        enemies = []
        for _ in range(int(difficulty)):
            enemy_type = random.choice(enemy_types)
            strength = random.randint(1, 10) * difficulty
            abilities = ["Fire Breath", "Ice Shard", "Poison"]
            enemy = Enemy(name=f"{enemy_type} {random.randint(1, 100)}", strength=strength, enemy_type=enemy_type, abilities=random.sample(abilities, 2))
            enemies.append(enemy)
        return enemies