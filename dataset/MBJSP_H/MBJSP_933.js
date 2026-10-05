function camelToSnake(text) {
    return text.replace(/([a-z])([A-Z])/g, "$1_$2").toLowerCase();
}
