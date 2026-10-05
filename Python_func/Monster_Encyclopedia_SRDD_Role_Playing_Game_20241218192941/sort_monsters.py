def sort_monsters(self, key):
        '''
        Sort monsters by a given attribute.
        '''
        try:
            self.monsters.sort(key=lambda monster: getattr(monster, key))
        except TypeError:
            print(f"Cannot sort by {key}. Ensure the attribute exists and is comparable.")
        except AttributeError:
            print(f"Attribute {key} does not exist.")