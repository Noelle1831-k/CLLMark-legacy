def summarize_features(self, features):
        '''
        Summarizes the extracted features for better understanding.
        Parameters:
            features (np.ndarray): Array of extracted audio features.
        Returns:
            summary (dict): Dictionary summarizing the features.
        '''
        summary = {
            'Mean Chroma STFT': features[0],
            'Std Chroma STFT': features[1],
            'Mean Chroma CQT': features[2],
            'Std Chroma CQT': features[3],
            'Mean Chroma CENS': features[4],
            'Std Chroma CENS': features[5],
            'Mean RMSE': features[6],
            'Std RMSE': features[7],
            'Mean Spectral Centroid': features[8],
            'Std Spectral Centroid': features[9],
            'Mean Spectral Bandwidth': features[10],
            'Std Spectral Bandwidth': features[11],
            'Mean Spectral Rolloff': features[12],
            'Std Spectral Rolloff': features[13],
            'Mean Zero Crossing Rate': features[14],
            'Std Zero Crossing Rate': features[15],
            'Mean MFCC': features[16],
            'Std MFCC': features[17],
            'Tempo': features[18]
        }
        return summary