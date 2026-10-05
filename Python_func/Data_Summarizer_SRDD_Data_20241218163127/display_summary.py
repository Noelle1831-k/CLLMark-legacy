def display_summary(self, summary):
        try:
            print("Data Summary Report")
            print("===================")
            print("\nNumerical Data Summary:")
            for column, stats in summary.get('Numerical Data Summary', {}).items():
                print(f"\nColumn: {column}")
                for stat, value in stats.items():
                    print(f"{stat.capitalize()}: {value}")
            print("\nCategorical Data Summary:")
            for column, distribution in summary.get('Categorical Data Summary', {}).items():
                print(f"\nColumn: {column}")
                for category, frequency in distribution.items():
                    print(f"{category}: {frequency}")
        except Exception as e:
            print(f"Error displaying summary: {e}")