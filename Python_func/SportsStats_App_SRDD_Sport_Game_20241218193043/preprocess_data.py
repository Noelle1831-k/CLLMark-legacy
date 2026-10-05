def preprocess_data(data):
    data.fillna(0, inplace=True)
    data['date'] = pd.to_datetime(data['date'])
    return data