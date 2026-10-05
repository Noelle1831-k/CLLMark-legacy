def drop_loot(self):
        '''
        Simulate dropping loot upon the monster's death.
        '''
        loot_table = ["Gold Coins", "Healing Potion", "Rare Gem", "Weapon Upgrade", "Armor Piece"]
        loot = random.sample(loot_table, random.randint(1, 3))
        print(f"{self.name} drops: {', '.join(loot)}")
        return loot