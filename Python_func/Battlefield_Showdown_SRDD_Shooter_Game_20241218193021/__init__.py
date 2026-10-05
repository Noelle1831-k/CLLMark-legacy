def __init__(self, name, health=100):
        self.name = name
        self.health = health
        self.position = (0, 0)
        self.weapon = weapon.Weapon()
        self.abilities = [ability.Ability()]