def store_responses():
    '''
    Store collected responses in a database.
    '''
    responses = collect_responses()
    try:
        with open('responses.json', 'a') as f:
            for response in responses:
                json.dump(response, f)
                f.write('\n')
        print("Feedback responses stored successfully.")
    except Exception as e:
        print(f"Failed to store responses: {e}")