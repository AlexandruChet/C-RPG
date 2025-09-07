# RPG Battle System (C++)

This project implements a simple RPG system in C++ with heroes, enemies, bosses and inventory.
The code demonstrates the principles of **OOP**: abstract classes, virtual methods, inheritance, polymorphism and working with dynamic memory via `shared_ptr`.

---

## 📌 Features

- **Character classes:**
- `Character` – a basic abstract class with characteristics: health, speed, strength.
- `Hero` – a hero with experience, can attack, kill enemies and pump characteristics.
- `Enemy` – a regular enemy.
- `Boss` – a strong opponent with more strength and health.

- **Inventory (`Inventory`):**
- Uses `vector<shared_ptr<Item>>` to store items.
- Methods: `addItem()`, `showInventory()`, `useItem()`.

- **Items (`Item`):**
- Abstract class `Item`.
- `Sword` – deals damage to the enemy.
- `Potion` – restores the hero's health.
- `Bow` – attacks from a distance, has a limited number of arrows.

- **Attacks and healing:**
- Characters have a chance to hit or miss.
- Enemies and bosses deal damage randomly.
- The hero gains experience and bonuses after killing an enemy.

---

## ▶️ Example of execution

When `main()` is run:

1. A hero, enemy and boss are created.
2. Items are added to the inventory: sword, potion and bow.
3. A list of the inventory is displayed.
4. Using items:

- The hero attacks the enemy with a sword.
- The hero drinks a potion.
- The hero shoots the boss with a bow.

---

## 🛠 Technologies used

- **C++17** (standard library: `iostream`, `vector`, `memory`, `cstdlib`, `ctime`).
- OOP approach: inheritance, virtual functions, abstract classes.
- Using **smart pointers (`shared_ptr`)** to work with items.

---

## 🚀 How to run

```bash
g++ main.cpp -o game
./game
```

# 🐾 Virtual Animal Game (C++)

This project is a simple console game in C++ where you can interact with a virtual animal.  
The code demonstrates the basics of **OOP (Object-Oriented Programming)**, working with **structs, classes, methods, and vectors**.

---

## 📂 Code Structure

### `struct Item`

- Stores the food name and its "rate".
- Used for the list of available food.

```cpp
struct Item {
    string text;
    double rate;
};
class Animal
Main class that describes the animal.

Fields:
level — animal level (1–5).

state — state (true/false).

happiness — happiness points.

sadness — sadness points.

age — animal age.

name — animal name.

items — list of food (vector<Item>).

Methods:
food() — show available food.

to_stroke() — pet the animal (+20 happiness).

to_feed() — feed the animal:

asks for food name and amount;

increases happiness if the food exists.

update() — updates the level depending on happiness.

wash() — wash the animal (+15 happiness).

class your_animal : public Animal
Inherits from Animal.

The constructor creates an animal "Dog" with initial values.

int game_loop()
Placeholder for the game loop (currently just returns 0).

int main()
Entry point of the program.

Calls game_loop().

🚀 How it works
When a your_animal object is created, the food list is initialized.

You can:

View food list (food()).

Pet the animal (to_stroke()).

Feed it (to_feed()).

Update the level (update()).

Wash it (wash()).

🔧 Possible Improvements
Implement a real game loop inside game_loop().

Add saving/loading of the animal state.

Introduce different types of animals.

Expand the mood system (happiness/sadness balance).

🛠 Compilation and Run
bash
g++ main.cpp -o game
./game
```
---

# 📘 calculator in C++

```cpp
#include <iostream> // for input and output (cin, cout)
#include <cmath> // for math functions: pow, sqrt

using namespace std;

int main() { 
double first_num, second_num; 
char op; 

// Enter the first number 
cout << "Write first number: "; 
cin >> first_num; 

// Operator input 
cout << "Write operator (+, -, *, /, ^ for power, s for square root): "; 
cin >> op; 

// If the operation is not 's' (the root), then the second number is required 
if (op != 's') { 
cout << "Write second number: "; 
cin >> second_num; 
} 

// Processing operations 
switch (op) { 
case '+': // addition 
cout << "Result: " << first_num + second_num << endl; 
break 

case '-': // subtraction 
cout << "Result: " << first_num - second_num << endl; 
break 

case '*': // multiplication 
cout << "Result: " << first_num * second_num << endl; 
break 

case '/': // division 
if (second_num == 0) { 
cout << "Error: division by zero!" << endl; 
} else { 
cout << "Result: " << first_num / second_num << endl; 
} 
break 

case '^': // exponentiation 
cout << "Result: " << pow(first_num, second_num) << endl; 
break 

case 's': // square root 
if (first_num < 0) { 
cout << "Error: negative number under sqrt!" << endl; 
} else { 
cout << "Result: " << sqrt(first_num) << endl; 
} 
break 

default: // unknown operator 
cout << "Unknown operator!" << endl; 
} 

return 0;
}
```

---

## 🔍 Detailed explanation

1. **Connecting libraries** 

* `<iostream>` — for working with `cin` and `cout`. 
* `<cmath>` — for mathematical functions (`pow' — exponentiation, `sqrt' — square root).

2. **Variables** 

* `double first_num, second_num;` → numbers (real numbers so that fractional values ​​can be entered). 
* `char op;` → operator (`+`, `-`, `*`, `/`, `^`, `s`).

3. **Data entry** 

* First, the program asks to enter the first number. 
* Then the operator. 
* If the operator is not `s` (root), the program asks for the second number.

4. **`switch` (selection operator)** 

* The program selects an action based on the entered symbol. 
* Supported: 

* `+` → addition 
* `-` → subtraction 
* `*` → multiplication 
* `/` → division (with division check by 0) 
* `^` → exponentiation 
* `s` → square root 
* If an unknown character is entered, ``Unknown operator!'' is displayed.

5. **Error handling** 

* When dividing by 0, `"Error: division by zero!"' is displayed. 
* When the root of a negative number → `"Error: negative number under sqrt!"`.

---

## 🖥️ An example of the program

```
Write first number: 9
Write operator (+, -, *, /, ^ for power, s for square root): s
Result: 3
```

```
Write first number: 5
Write operator (+, -, *, /, ^ for power, s for square root): *
Write second number: 4
Result: 20
```

```
Write first number: 7
Write operator (+, -, *, /, ^ for power, s for square root): /
Write second number: 0
Error: division by zero!
```

````markdown
# Binary Search Number Guessing

This project is a simple example of implementing **binary search** in C++, where the computer tries to guess a number that the user has guessed (it is given in advance in the code).

## 🔍 How the program works
- The computer has a range from `1` to `1000`.
- It calculates the middle (`(min + max) / 2`) and makes a guess.
- If the guess:
- greater than the target number → searches lower,
- less than the target number → searches higher,
- equal to the number → the program completes successfully.
- The number of attempts is counted and displayed on the screen.

## 📂 File structure
- `algorithm.cpp` is the main file with the code.
- `algorithm.exe` is the compiled executable file (Windows).

## ▶️ Example of running
```bash
./algorithm.exe
````

The output in the terminal might look like this:

```
Computer guesses: 500
Too high! Trying lower...
Computer guesses: 250
Too low! Trying higher...
Computer guesses: 375
Too low! Trying higher...
Computer guesses: 437
Too low! Trying higher...
Computer guesses: 468
Too high! Trying lower...
Computer guesses: 452
Too low! Trying higher...
Computer guesses: 460
Computer found the number 456 in 8 attempts!
```

## 🛠️ How to compile

You can compile the code with the command (for g++):

```bash
g++ algorithm.cpp -o algorithm.exe
```

# File I/O and Struct Example in C++

This C++ program demonstrates basic file input/output operations and usage of a `struct` to store data. It shows how to write to a file, read from a file, and store structured data using `vector`.

## Features

1. **Write text to a file**

   * Appends `"Hello World!"` to a file named `text.txt`.

2. **Read text from a file**

   * Reads all lines from `text.txt` and prints them to the console.

3. **Store structured data**

   * Defines a `Point` struct with `x` and `y` coordinates.
   * Creates a `vector<Point>` containing several points.

4. **Write structured data to a file**

   * Overwrites `text.txt` with the coordinates of the points.

5. **Read structured data from a file**

   * Reads the points back into a new vector and prints them to the console.

## How It Works

1. **Appending text**

   ```cpp
   ofstream out("text.txt", ios::app);
   out << "Hello World!" << endl;
   ```

2. **Reading text**

   ```cpp
   ifstream in("text.txt");
   while (getline(in, line)) {
       cout << line << endl;
   }
   ```

3. **Writing points**

   ```cpp
   vector<Point> points{Point{0,0}, Point{4,5}, Point{-5,7}};
   for (const Point &point : points) {
       out << point.x << " " << point.y << endl;
   }
   ```

4. **Reading points**

   ```cpp
   vector<Point> new_points;
   while (in >> x >> y) {
       new_points.push_back(Point(x, y));
   }
   ```

## Output Example

```
Hello World!
Point X:0 Y:0
Point X:4 Y:5
Point X:-5 Y:7
```

## Requirements

* C++ compiler (C++11 or later)
* Standard library `<iostream>`, `<fstream>`, `<string>`, `<vector>`

