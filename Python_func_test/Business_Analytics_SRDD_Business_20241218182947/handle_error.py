def handle_error(error_message):
    try:
        logging.error(error_message)
    except Exception as e:
        raise Exception(f"Error handling error: {e}")