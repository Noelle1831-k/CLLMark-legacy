def add_threat_to_database(self, threat_database):
        '''Add a new threat to the database.'''
        self.display("\n--- Add Threat ---")
        new_threat = self.get_user_input("Enter the name of the threat: ")
        threat_database.add_threat(new_threat)