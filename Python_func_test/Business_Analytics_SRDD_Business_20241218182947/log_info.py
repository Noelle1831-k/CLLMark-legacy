def log_info(info_message):
    try:
        logging.info(info_message)
    except Exception as e:
        raise Exception(f"Error logging info: {e}")