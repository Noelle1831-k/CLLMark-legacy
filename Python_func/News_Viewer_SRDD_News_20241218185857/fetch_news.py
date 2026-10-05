def fetch_news(source):
    try:
        response = requests.get(source)
        response.raise_for_status()
        utils.log_info(f"Successfully fetched news from {source}")
        return response.json()
    except requests.exceptions.HTTPError as http_err:
        utils.log_error(f"HTTP error occurred: {http_err}")
    except requests.exceptions.ConnectionError as conn_err:
        utils.log_error(f"Connection error occurred: {conn_err}")
    except requests.exceptions.Timeout as timeout_err:
        utils.log_error(f"Timeout error occurred: {timeout_err}")
    except requests.exceptions.RequestException as req_err:
        utils.log_error(f"Request error occurred: {req_err}")
    return []