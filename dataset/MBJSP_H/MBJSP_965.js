function camelToSnake(text) {
    return text.replace(/\W+/g, "_")
        .replace(/([a-z])([A-Z])/g, "$1_$2")
        .toLowerCase();
}
