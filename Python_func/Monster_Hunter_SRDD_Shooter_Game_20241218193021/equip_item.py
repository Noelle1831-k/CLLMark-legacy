def equip_item(self, item):
        if isinstance(item, weapon.Weapon):
            self.weapons.append(item)
        elif isinstance(item, armor.Armor):
            self.armor = item