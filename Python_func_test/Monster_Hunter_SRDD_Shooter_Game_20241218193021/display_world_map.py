def display_world_map(self):
        '''
        Display the current state of the world, including unlocked areas and their details.
        '''
        print("\n--- World Map ---")
        for area_id in range(1, self.areas_unlocked + 1):
            landscape = self.landscapes[area_id - 1]
            monster_zone = self.monster_zones.get(area_id, {})
            print(f"Area {area_id}:")
            print(f"  Terrain: {landscape['Terrain']}")
            print(f"  Weather: {landscape['Weather']}")
            print(f"  Special Features: {', '.join(landscape['Special Features'])}")
            print(f"  Monster Zone: Difficulty {monster_zone.get('Difficulty', 'N/A')}, Monsters: {monster_zone.get('Monsters', 'None')}")
        print("-----------------\n")