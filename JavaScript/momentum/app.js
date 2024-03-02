/* // const and let
const a = 5;
const b = 2;
let myName = "Kwon"; // variable name에는 공백X 대문자 사용 -> py "_" 사용

console.log(a + b);
console.log(a * b);
console.log(a / b);
console.log("hello " + myName);

myName = "KBC";

console.log("your new name is " + myName); */

/* // Booleans
const amIFat = null;
let something;
console.log(something, amIFat); */

/* // Array
const daysOfWeek = ["mon", "tue", "wed", "thu", "fri", "sat"];

// Get Item from Array
console.log(daysOfWeek);

// Add one more day to the array
daysOfWeek.push("sun");

console.log(daysOfWeek); */

/* // Object
 const player = {
    name: "Kwon",
    points: 10,
    fat: true,
};
// console.log(player["name"]); // console.log(player.name);
console.log(player);
// player.fat = false; // player = false; 오류 -> const는 변경 불가
player.lastName = "potato";
player.points = player.points + 15; // 10+15
console.log(player); */

/* // function 1
function sayHello(nameOfPerson, age){
    console.log("Hello my name is " + nameOfPerson + " and I'm " + age);
}

sayHello("Kwon", 10);
sayHello("Moon", 23);
sayHello("Dahye", 21); */

// function 2
function plus(a, b){
    console.log(a + b);
}

plus(8, 60);