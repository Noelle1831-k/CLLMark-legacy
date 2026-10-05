def get_area_info(self, area_id):
        '''
        Retrieve detailed information about a specific area, including its landscape and monster zone.
        '''
        if 1 <= area_id <= self.areas_unlocked:
            landscape = self.landscapes[area_id - 1]
            monster_zone = self.monster_zones.get(area_id, {})
            area_info = {
                "Landscape": landscape,
                "Monster Zone": monster_zone,
            }
            return area_info
        else:
            print(f"Area {area_id} is not unlocked or does not exist.")
            return None