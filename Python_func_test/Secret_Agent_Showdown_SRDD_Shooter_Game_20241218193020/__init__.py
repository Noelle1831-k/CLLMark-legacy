def __init__(self, level_number):
        self.level_number = level_number
        self.enemies = [enemy.Enemy((i * 10, i * 10)) for i in range(5)]
        self.objectives = ["infiltrate_base", "eliminate_target"]