def exponential_smoothing(self, data, alpha=0.5):
        try:
            exp_smooth = data.ewm(alpha=alpha).mean()
            print("Exponential smoothing applied.")
            return exp_smooth
        except Exception as e:
            print(f"Error in exponential smoothing: {e}")