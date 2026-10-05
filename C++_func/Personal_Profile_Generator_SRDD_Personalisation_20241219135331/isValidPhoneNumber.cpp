bool InputValidator::isValidPhoneNumber(string phoneNumber) {
    const regex pattern("\\+?[0-9]{10,15}");
    return regex_match(phoneNumber, pattern);
}