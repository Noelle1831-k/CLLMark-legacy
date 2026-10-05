def add_monster_zone(self, area_id):
        '''
        Add a monster zone for the specified area with randomized difficulty and monster spawns.
        Each zone includes monster types and a difficulty level.
        '''
        if area_id <= self.max_areas:
            difficulty = area_id * 2  # Increase difficulty with each new area
            monsters = random.choices(
                ["Goblin", "Ogre", "Dragon", "Werewolf", "Skeleton", "Griffin"],
                k=random.randint(3, 6)
            )
            zone = {
                "Difficulty": difficulty,
                "Monsters": monsters,
            }
            self.monster_zones[area_id] = zone
            print(f"Monster zone added for Area {area_id}: {zone}")