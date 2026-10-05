int start = text.find(pattern);
if(start != string::npos) {
    return {start, start + pattern.length() - 1};
}
return {};
}