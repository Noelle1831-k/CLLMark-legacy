def calculate_z_score(data):
    try:
        mean = np.mean(data)
        std = np.std(data)
        z_scores = (data - mean) / std
        print("Z-scores calculated successfully.")
        return z_scores
    except Exception as e:
        print(f"Error calculating z-scores: {e}")
        return np.zeros(data.shape)