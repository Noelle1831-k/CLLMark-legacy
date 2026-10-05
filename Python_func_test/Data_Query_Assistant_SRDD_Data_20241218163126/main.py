def main():
    dataset = Dataset()
    dataset.load_data('data.csv')
    query_engine = QueryEngine(dataset)
    web_interface = WebInterface(query_engine)
    web_interface.start_server()