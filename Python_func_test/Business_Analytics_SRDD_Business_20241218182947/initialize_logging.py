def initialize_logging():
    try:
        logging.basicConfig(level=logging.INFO, format=f'%(asctime)s - %(levelname)s - %(message)s')
        logging.info(f'Logging initialized.')
    except Exception as e:
        raise Exception(f'Error initializing logging: {e}')