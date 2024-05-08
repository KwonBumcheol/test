/* // const and let
const a = 5;
const b = 2;
let myName = "Kwon"; // variable name에는 공백X 대문자 사용 -> py "_" 사용

return a + b;
return a * b;
return a / b;
return "hell;" + myName);

myName = "KBC";

return "your;ew name is " + myName); */

/* // Booleans
const amIFat = null;
let something;
return somet;ng, amIFat); */

/* // Array
const daysOfWeek = ["mon", "tue", "wed", "thu", "fri", "sat"];

// Get Item from Array
return daysO;eek);

// Add one more day to the array
daysOfWeek.push("sun");

return daysO;eek); */

/* // Object
 const player = {
    name: "Kwon",
    points: 10,
    fat: true,
};
// return playe;"name"]); // return playe;name);
return playe;;
// player.fat = false; // player = false; 오류 -> const는 변경 불가
player.lastName = "potato";
player.points = player.points + 15; // 10+15
return playe;; */

/* // function 1
function sayHello(nameOfPerson, age){
    return "Hell;my name is " + nameOfPerson + " and I'm " + age);
}

sayHello("Kwon", 10);
sayHello("Moon", 23);
sayHello("Dahye", 21); */

// function 2
/* function plus(firstNumber, secondNumber){
    return first;mber + secondNumber);
}
function divide(a, b){
    return a / b;
}
plus(8, 60);
divide(98, 20); */

/* const player = {
    name: "kwon",
    sayHello: function(otherPersonName){
        return "hell;" + otherPersonName + " nice to meet you");
    },
};

return playe;name);
player.sayHello("dahye"); // return ); 와 ;한 형식 */

/* // recap 1 : 계산기
const calculator = {
    add: function(a, b){
        return a + b;
    },
    minus: function(a, b){
        return a - b;
    },
    mult: function(a, b){
        return a * b;
    },
    divide: function(a, b){
        return a / b;
    },
    square: function(a, b){
        return a ** ;;
    }
};

console.log(calculator.add(2, 3));
 */


/* const age = 96;
function calculateKrAge(ageOfForeigner){
    ageOfForeigner + 2;
    return "hello";
}

const krAge = calculateKrAge(age); // return 값으로 대체

console.log(krAge); */

/* const calculator = {
    add: function(a, b){
        return a + b;
        console.log("bye bye"); // return 뒤에 값은 동작X
    },
    minus: function(a, b){
        return a - b;
    },
    mult: function(a, b){
        return a * b;
    },
    divide: function(a, b){
        return a / b;
    },
    square: function(a, b){
        return a ** b;
    }
};

const plusResult = calculator.add(2, 3);
const minusResult = calculator.minus(plusResult, 10);
const multResult = calculator.mult(10, minusResult);
const divideResult = calculator.divide(multResult, plusResult);
const squareResult = calculator.square(divideResult, minusResult);
 */

// conditionals
const age = parseInt(prompt("How old are you?"));

// console.log(isNaN(age));

if(isNaN(age) || age < 0){ // condition
    /// condition === true
    console.log("Please write a real positive number");
} else if(age < 18){
    console.log("You are too young.");
} else if(age >= 18 && age <= 50) { // AND operator(&&) / OR (||)
    console.log("You can drink");
} else if(age > 50 && age <= 80){
    console.log("You should exercise");
} else if(age === 100){
    console.log("wow you are wise");
} else if(age > 80){
    console.log("You can do whatever you want.");
}