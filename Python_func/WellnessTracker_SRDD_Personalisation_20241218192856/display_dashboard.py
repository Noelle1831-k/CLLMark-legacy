def display_dashboard(self, data, analysis, recommendations):
        print("\n--- Wellness Dashboard ---")
        print("Physical Activity Level:", data['physical_activity'])
        print("Sleep Quality:", data['sleep_quality'])
        print("Nutrition Score:", data['nutrition'])
        print("Stress Levels:", data['stress_levels'])
        print("Mental Health Score:", data['mental_health'])
        print("\n--- Analysis ---")
        for key, value in analysis.items():
            print(f"{key.replace('_', ' ').title()}: {value}")
        print("\n--- Recommendations ---")
        for recommendation in recommendations:
            print("-", recommendation)