def initialize_logging():
    try:
        logging.basicConfig(level=logging.INFO, format='%(asctime)s - %(levelname)s - %(message)s')
        logging.info("Logging initialized.")
    except Exception as e:
        raise Exception(f"Error initializing logging: {e}")