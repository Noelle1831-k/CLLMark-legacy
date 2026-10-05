function checkEmail(email) {
  return email.match(/(@.+\.+)|(mailto:.+@.+\.+)|(gmail:.+@.+\.+)|(com:.+@.+\\.+)$/)
    ? "Valid Email"
    : "Invalid Email";
}
