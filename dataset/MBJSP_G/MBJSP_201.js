function chklist(lst) {
const first = lst[0];
return lst.every(item => item === first);
}
