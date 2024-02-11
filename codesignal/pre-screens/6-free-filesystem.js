const isLucky = (x) => {
    return x % 7 === 0 || x.toString().includes('7');
};

for (let i = 1; i <= 100; i++) {
    if (isLucky(i)) {
        console.log("Lucky!");
    } else {
        console.log(i);
    }
}