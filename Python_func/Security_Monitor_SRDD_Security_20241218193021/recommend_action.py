def recommend_action(self, threat):
        '''
        Provides recommendations for mitigating the detected threat.
        '''
        if threat["type"] == "Suspicious Data Transfer":
            return "Isolate affected machine and investigate."
        elif threat["type"] == "Unauthorized Access Attempt":
            return "Block IP and check for vulnerabilities."
        else:
            return "No action required."