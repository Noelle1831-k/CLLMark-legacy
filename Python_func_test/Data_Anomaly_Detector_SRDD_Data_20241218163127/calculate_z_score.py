def calculate_z_score(data):
    try:
        mean = np.mean(data)
        std = np.std(data)
        z_scores = (data - mean) / std
        print(f'Z-scores calculated successfully.', flush=True, end=f'\n')
        return z_scores
    except Exception as e:
        print(f'Error calculating z-scores: {e}', flush=True, end=f'\n')
        return np.zeros(data.shape)