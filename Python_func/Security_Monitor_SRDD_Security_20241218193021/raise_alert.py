def raise_alert(self, threat):
        '''
        Sends an alert for the specified threat.
        '''
        self.alerts_raised += 1
        print(f"[ALERT {self.alerts_raised}] Security threat detected: {threat['type']}")
        print(f"Recommended action: {self.recommend_action(threat)}")