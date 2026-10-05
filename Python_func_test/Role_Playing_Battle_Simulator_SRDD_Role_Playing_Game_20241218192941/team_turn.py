def team_turn(self, attacking_team, defending_team):
        for character in attacking_team.get_alive_characters():
            target = random.choice(defending_team.get_alive_characters())
            if target.health > 0:
                action = random.choice(['attack', 'ability'])
                if action == 'attack':
                    character.attack(target)
                else:
                    ability = random.choice(character.abilities)
                    character.use_ability(ability.name, target)