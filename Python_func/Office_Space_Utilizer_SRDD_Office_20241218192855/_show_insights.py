def _show_insights(self, insights):
        '''
        Display the insights extracted from the data analysis.
        '''
        print("\n--- Insights ---")
        for key, value in insights.items():
            if isinstance(value, pd.Timestamp):
                print(f"{key}: {value.strftime('%Y-%m-%d %H:%M:%S')}")
            elif isinstance(value, pd.DatetimeIndex):
                print(f"{key}: {', '.join([ts.strftime('%Y-%m-%d %H:%M:%S') for ts in value])}")
            else:
                print(f"{key}: {value}")