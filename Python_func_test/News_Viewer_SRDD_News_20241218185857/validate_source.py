def validate_source(source):
    is_valid = source.startswith("https://newsapi.org")
    utils.log_info(f"Source validation for {source}: {is_valid}")
    return is_valid