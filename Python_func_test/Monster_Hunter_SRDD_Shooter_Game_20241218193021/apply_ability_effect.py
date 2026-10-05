def apply_ability_effect(self, ability, target):
        '''
        Apply the effect of a specific ability to the target (e.g., player).
        '''
        if ability == "Quick Strike":
            damage = self.attack_power + 5
            print(f"Quick Strike deals {damage} damage!")
            target.take_damage(damage)
        elif ability == "Intimidate":
            print(f"Player's attack power is reduced temporarily!")
            target.attack_power = max(0, target.attack_power - 5)
        elif ability == "Power Slam":
            damage = self.attack_power * 2
            print(f"Power Slam crushes the target for {damage} damage!")
            target.take_damage(damage)
        elif ability == "Roar":
            print(f"{self.name} roars, increasing its defense!")
            self.defense += 10
        elif ability == "Regenerate":
            heal = 20
            self.health += heal
            print(f"{self.name} regenerates {heal} health!")
        elif ability == "Flame Breath":
            damage = self.attack_power * 3
            print(f"Flame Breath engulfs the target for {damage} damage!")
            target.take_damage(damage)
        elif ability == "Earthquake":
            damage = self.attack_power * 1.5
            print(f"Earthquake shakes the ground, dealing {damage} damage!")
            target.take_damage(damage)
        elif ability == "Dark Aura":
            print(f"Dark Aura weakens the player's abilities!")
            target.abilities = []
        elif ability == "Summon Minions":
            print(f"{self.name} summons additional minions!")
            # Simulate summoning new monsters
            for _ in range(random.randint(1, 3)):
                minion = Monster(level=self.level - 1)
                minion.spawn()