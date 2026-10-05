def use(self, user, target):
        if self.effect == "heal":
            user.health += 20
        elif self.effect == "boost":
            user.attack_power += 5
        elif self.effect == "shield":
            user.defense += 5
        elif self.effect == "fireball":
            damage = random.randint(10, 30)
            target.take_damage(damage)
        elif self.effect == "lightning":
            damage = random.randint(15, 25)
            target.take_damage(damage)
        elif self.effect == "backstab":
            damage = random.randint(20, 35)
            target.take_damage(damage)
        return self.effect