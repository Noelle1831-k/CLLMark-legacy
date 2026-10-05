function isDecimal(num) {
const regex = /^\d+\.\d{2}$/;
return regex.test(num);
}
