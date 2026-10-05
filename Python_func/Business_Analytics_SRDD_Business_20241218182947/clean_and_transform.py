def clean_and_transform(data):
    try:
        # Drop missing values
        data = data.dropna()
        # Convert data types
        data['Date'] = pd.to_datetime(data['Date'])
        data['Sales'] = data['Sales'].astype(float)
        # Aggregate data
        aggregated_data = data.groupby('Category').sum()
        # Add additional transformations
        aggregated_data['Sales Growth'] = aggregated_data['Sales'].pct_change().fillna(0)
        return aggregated_data
    except Exception as e:
        raise Exception(f"Error processing data: {e}")