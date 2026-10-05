def remove_threat(self, threat):
        if threat in self.quarantined_threats:
            self.quarantined_threats.remove(threat)
            print(f"Threat removed: {threat}")