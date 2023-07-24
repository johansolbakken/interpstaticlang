# Interpred static language

"I just want to be able to make objects and interfaces, but I dont want to write all the assembly."

## Build and run
~~~bash
git clone --recursive https://github.com/johansolbakken/interpstaticlang
mkdir interpstaticlang-build
cd interpstaticlang-build
cmake ../interpstaticlang
make
./islc/islc < ../interpstaticlang/examples/main.txt
~~~ 

## Project
- islc: compiling the code into intermediate form that will be run by interpreter.

## Goal
* String manipulation
* File reading

### Entry point
~~~
func main(args: string[]) {
    
} 
~~~

### Function
~~~
func add(a: int, b: int): int {
    return a + b
}
~~~

### Builtin types
~~~
int (64-bit)
string
float
bool
~~~

### Classes
~~~
pub class Dog {
    age: int
}

pub func Dog::new() : Dog {
    let dog = Dog()
    dog.age = 5
    return dog
}

pub func Dog::bark() {
    println("Bark! And I am {}", age);
}
~~~

### Variables
~~~
let dog = new Dog()
~~~