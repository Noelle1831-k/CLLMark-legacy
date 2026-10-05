def log_event(message):
    '''
    Log an event with the specified message.
    '''
    logging.basicConfig(filename='privacyshield.log', level=logging.INFO)
    logging.info(message)