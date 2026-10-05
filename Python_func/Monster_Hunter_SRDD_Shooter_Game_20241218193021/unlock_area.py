def unlock_area(self):
        '''
        Unlock a new area for the player if areas are still available.
        Unlocking new areas introduces tougher monsters and rarer resources.
        '''
        if self.areas_unlocked < self.max_areas:
            self.areas_unlocked += 1
            print(f"Area {self.areas_unlocked} has been unlocked!")
            self.add_monster_zone(self.areas_unlocked)
        else:
            print("All areas have already been unlocked.")