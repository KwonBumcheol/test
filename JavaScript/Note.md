JavaScript
==========
## 1. const and let
### const : 고정값(variable 변경 불가)

### let : 새로운 값(처음에만 사용)
<pre>
<code>
const a = 5;
const b = 2;
let myName = "Kwon"; // variable name에는 공백X 대문자 사용 -> py "_" 사용

console.log(a + b);
console.log(a * b);
console.log(a / b);
console.log("hello " + myName);

myName = "KBC";

console.log("your new name is " + myName);
</code>
</pre>

### var : 고정값 > 예전에 쓰던 variable

단점 : 밑에서 변화 유무를 알 수 없음.

<pre>
<code>
var a = 5;
var b = 2;
var myName = "Kwon";
</code>
</pre>

## 2. Booleans

### True / False
true = 1
false = 0 
false : 값이 존재 ≠ null : 아무것도 없음(nothing)

<pre>
<code>
const amIFat = null;
let something; // 메모리 존재 but! 값이 없음 > undefined
console.log(something, amIFat);
</code>
</pre>

## 3. Array

- 배열 항목은 쉼표(,)로 분리해야 함
- 대괄호([])로 묶어야함

<pre>
<code>
const daysOfWeek = ["mon", "tue", "wed", "thu", "fri", "sat"];

// Get Item from Array
console.log(daysOfWeek[5]);

// Add one more day to the array
daysOfWeek.push("sun");

console.log(daysOfWeek);
</code>
</pre>

## 4. Object

- 중괄호({}) 내부에 property(특성)을 작성
- : 사용
### console = object

<pre>
<code>
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
console.log(player);
</code>
</pre>

## 5. Functions

### 캡슐화

- argument  
  ex) sayHello(<U>**"Kwon"**</U>);

<pre>
<code>
function sayHello(nameOfPerson, age){
    console.log("Hello my name is " + nameOfPerson + " and I'm " + age);
}

sayHello("Kwon", 10);
sayHello("Moon", 23);
sayHello("Dahye", 21);
</code>
</pre>

- function 안에 데이터를 가질 경우

<pre>
<code>
const player = {
    name: "kwon",
    sayHello: function(otherPersonName){
        console.log("hello " + otherPersonName + " nice to meet you");
    },
};

console.log(player.name);
player.sayHello("dahye"); // console.log(); 와 동일한 형식
</code>
</pre>

## Recap 1 : 계산기

<pre>
<code>
const calculator = {
    add: function(a, b){
        console.log(a + b);
    },
    minus: function(a, b){
        console.log(a - b);
    },
    mult: function(a, b){
        console.log(a * b);
    },
    divide: function(a, b){
        console.log(a / b);
    },
    square: function(a, b){
        console.log(a ** b);
    }
};

calculator.add(2, 2);
calculator.minus(2, 2);
calculator.mult(2, 2);
calculator.divide(2, 2);
calculator.square(2, 2);
</code>
</pre>

### function에 console.log 사용X

<pre><code>
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
        return a ** b;
    }
};

const plusResult = calculator.add(2, 3);
const minusResult = calculator.minus(plusResult, 10);
const multResult = calculator.mult(10, minusResult);
const divideResult = calculator.divide(multResult, plusResult);
const squareResult = calculator.square(divideResult, minusResult);
</code></pre>