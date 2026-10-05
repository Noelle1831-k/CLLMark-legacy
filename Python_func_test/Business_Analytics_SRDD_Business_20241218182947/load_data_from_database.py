def load_data_from_database(connection_string, query):
    try:
        import sqlalchemy
        engine = sqlalchemy.create_engine(connection_string)
        data = pd.read_sql(query, engine)
        return data
    except Exception as e:
        raise Exception(f'Error loading data from database: {e}')