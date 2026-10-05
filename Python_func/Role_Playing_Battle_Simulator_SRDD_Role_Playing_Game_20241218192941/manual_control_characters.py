def manual_control_characters(self):
        for team in self.teams:
            for character in team.characters:
                print(f"Controlling {character.name} from {team.name}")
                while character.health > 0:
                    action = input(f"Choose action for {character.name} (attack/ability): ").strip().lower()
                    if action == "attack":
                        target_team = self.teams[1] if team == self.teams[0] else self.teams[0]
                        target = random.choice(target_team.get_alive_characters())
                        damage = character.attack(target)
                        print(f"{character.name} attacked {target.name} for {damage} damage.")
                        break
                    elif action == "ability":
                        ability_name = input(f"Choose ability for {character.name} ({', '.join([ability.name for ability in character.abilities])}): ").strip()
                        target_team = self.teams[1] if team == self.teams[0] else self.teams[0]
                        target = random.choice(target_team.get_alive_characters())
                        effect = character.use_ability(ability_name, target)
                        print(f"{character.name} used {ability_name} on {target.name} with effect: {effect}.")
                        break
                    else:
                        print("Invalid action. Please choose again.")