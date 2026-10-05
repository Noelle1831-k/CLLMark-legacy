string result;
bool capitalize = true;
for (char ch : word) {
    if (ch == '_') {
        capitalize = true;
    } else {
        result += capitalize ? toupper(ch) : ch;
        capitalize = false;
    }
}
return result;
}