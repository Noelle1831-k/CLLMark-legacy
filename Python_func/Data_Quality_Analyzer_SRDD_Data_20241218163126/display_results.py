def display_results(self, consistency, accuracy, completeness, validity, insights):
        '''
        Display the results in a user-friendly manner.
        '''
        print("Data Quality Results:")
        print(f"Consistency: {'Pass' if consistency else 'Fail'}")
        print(f"Accuracy: {'Pass' if accuracy else 'Fail'}")
        print(f"Completeness: {'Pass' if completeness else 'Fail'}")
        print(f"Validity: {'Pass' if validity else 'Fail'}")
        print(f"Overall Quality Score: {insights['quality_score']}%")