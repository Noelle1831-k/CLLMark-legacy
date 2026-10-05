def add_threat(self, threat):
        if threat not in self.threats:
            self.threats.append(threat)
            print(f"Threat {threat} added to database.")