def scavenge(self):
        found_item = random.choice(['weapon', 'equipment'])
        if found_item == 'weapon':
            weapon = Weapon()
            self.weapons.append(weapon)
            print(f"{self.character.name} found a weapon: {weapon.name}.")
        else:
            equipment = Equipment()
            self.equipment.append(equipment)
            print(f"{self.character.name} found equipment: {equipment.name}.")