def generate_report(self, tasks):
        '''
        Generates a productivity report.
        '''
        self.report = []
        for task in tasks:
            self.report.append({
                "name": task["name"],
                "progress": task["progress"]
            })