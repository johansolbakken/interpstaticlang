# Interpred static language

"I just want to be able to make objects and interfaces, but I dont want to write all the assembly."

## Entry point
~~~
func main(args: string[]) {
    
} 
~~~

## Function
~~~
func add(a: int, b: int): int {
    return a + b
}
~~~

## Builtin types
~~~
int (64-bit)
string
float
bool
~~~

## Classes
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

## Variables
~~~
let dog = new Dog()
~~~

# Goal
* String manipulation
* File reading