def analyze_data(self, data):
        normalized_data = normalize_data(data)
        insights = {
            'average_activity': calculate_average([normalized_data['physical_activity']]),
            'average_sleep': calculate_average([normalized_data['sleep_quality']]),
            'average_nutrition': calculate_average([normalized_data['nutrition']]),
            'average_stress': calculate_average([normalized_data['stress_levels']]),
            'average_mental_health': calculate_average([normalized_data['mental_health']])
        }
        return insights