def display_dashboard(self, stats, correlations, outliers):
        # Display dashboard
        print("Statistics:")
        for key, value in stats.items():
            print(f"{key}: {value}")
        print("\nCorrelations:")
        print(correlations)
        print("\nOutliers:")
        print(outliers)