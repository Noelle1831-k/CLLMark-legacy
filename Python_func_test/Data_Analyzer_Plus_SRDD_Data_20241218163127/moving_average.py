def moving_average(self, data, window_size=3):
        try:
            moving_avg = data.rolling(window=window_size).mean()
            print('Moving average calculated.')
            return moving_avg
        except Exception as e:
            print(f'Error in moving average: {e}')