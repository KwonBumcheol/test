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

