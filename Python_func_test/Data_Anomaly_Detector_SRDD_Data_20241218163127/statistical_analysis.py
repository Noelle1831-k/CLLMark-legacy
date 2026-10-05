def statistical_analysis(self, data):
        try:
            z_scores = calculate_z_score(data)
            anomalies = np.where(np.abs(z_scores) > 3)
            print(f"Statistical anomalies found: {len(anomalies[0])}")
            return anomalies
        except Exception as e:
            print(f"Error in statistical analysis: {e}")
            return []