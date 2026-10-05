def preprocess_data(data):
    # Convert categorical data to numeric if necessary
    data = pd.get_dummies(data)
    # Fill missing values
    data.fillna(method='ffill', inplace=True)
    # Drop duplicates
    data.drop_duplicates(inplace=True)
    # Ensure data is a 2D array
    if len(data.columns) == 1:
        data = data.values.reshape(-1, 1)
    return data