def load_data(self):
        '''
        Load initial data into the data store.
        '''
        self.characters.append(Character("Aragorn", "A ranger from the North.", "Rangers"))
        self.locations.append(Location("Rivendell", "An elven refuge.", "Eriador"))
        self.factions.append(Faction("Rangers", "Protectors of the North.", "Aragorn"))
        self.events.append(Event("Battle of Helm's Deep", "A major battle in the War of the Ring.", "3019 TA"))