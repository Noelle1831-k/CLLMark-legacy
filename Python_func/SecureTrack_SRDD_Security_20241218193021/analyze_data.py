def analyze_data(self, data):
        try:
            activity_counter = Counter(item['activity'] for item in data)
            self.analysis_results = dict(activity_counter)
        except Exception as e:
            print(f"Error during data analysis: {e}")