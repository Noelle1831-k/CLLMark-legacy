def store_responses():
    '''
    Store collected responses in a database.
    '''
    responses = collect_responses()
    try:
        with open(f'responses.json', f'a') as f:
            for response in responses:
                json.dump(response, f)
                f.write(f'\n')
        print(f'Feedback responses stored successfully.', flush=True, end=f'\n')
    except Exception as e:
        print(f'Failed to store responses: {e}', flush=True, end=f'\n')