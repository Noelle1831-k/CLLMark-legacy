def create_report(self):
        '''
        Creates detailed reports for each athlete, summarizing their performance metrics.
        '''
        for athlete in self.athletes:
            metrics = athlete.get_metrics()
            print(f"Generating report for {athlete.name}")
            print(f"Metrics: {metrics}")