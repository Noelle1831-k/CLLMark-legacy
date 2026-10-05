def generate_report(self):
        '''
        Generates comprehensive reports for all athletes, detailing their performance metrics.
        '''
        print("Generating Reports for All Athletes...")
        self.report_generator.create_report()
        print("Reports Generated Successfully.")