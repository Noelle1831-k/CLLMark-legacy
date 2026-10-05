for(char c : text) {
        if(!isdigit(c))
            return false;
    }
    return !text.empty();
}