def apply_effect(self, player):
        '''
        Apply the ability's effect to the player.
        '''
        if self.effect == "heal":
            player.health += 20
            print(f"{player} healed by 20 points.")
        elif self.effect == "boost_attack":
            for weapon in player.weapons:
                weapon.power += 5
            print(f"{player}'s attack power boosted by 5 for each weapon.")
        elif self.effect == "shield":
            player.armor.defense += 10
            print(f"{player}'s defense increased by 10.")