
# 🎮 C++ Mini Projects Collection

> Welcome to my **C++ Learning Projects Collection** 🚀  
This repository contains multiple **mini-projects** that demonstrate the power of C++.  
They cover topics such as **OOP, inheritance, polymorphism, algorithms, file I/O, and more**.  

Each project has a description, code samples, explanations, and instructions to run.  
Perfect for **students, beginners, and enthusiasts** who want to practice modern **C++17**.

---

# 📑 Table of Contents

1. ⚔️ [RPG Battle System](#-rpg-battle-system)  
2. 🐾 [Virtual Animal Game](#-virtual-animal-game)  
3. 🧮 [Calculator](#-calculator-in-c)  
4. 🔢 [Binary Search Guessing Game](#-binary-search-number-guessing)  
5. 📂 [File I/O + Struct Example](#-file-io-and-struct-example)  
6. 📘 [Detailed C++ Explanations](#-detailed-c-explanations)  

---

# ⚔️ RPG Battle System

This project implements a **mini RPG battle simulator** in C++.

It demonstrates **Object-Oriented Programming (OOP)**:  
- Abstract classes  
- Virtual methods  
- Inheritance  
- Polymorphism  
- Smart pointers (`shared_ptr`)  

---

## 📌 Features

- **Character system**:
  - `Character` → abstract base class with stats: health, strength, speed
  - `Hero` → player-controlled, gains XP, can attack, heal, level up
  - `Enemy` → basic opponent with random attacks
  - `Boss` → stronger enemy with higher health and damage

- **Inventory system**:
  - Stores items inside `vector<shared_ptr<Item>>`
  - Items include:
    - 🗡️ `Sword` (damage)
    - 🧪 `Potion` (heal HP)
    - 🏹 `Bow` (ranged attack, limited arrows)

- **Combat system**:
  - Randomized damage
  - Hit/miss chance
  - Gaining XP and bonuses for kills

---

## 📂 Class Diagram (Simplified)

```

Character (abstract)
│
├── Hero
│    ├── inventory: vector<Item>
│    ├── xp: int
│
├── Enemy
│
└── Boss

```
```

Item (abstract)
│
├── Sword
├── Potion
└── Bow

```

---

## ▶️ Example Run

```

\[Hero enters the battle!]

Hero attacks Enemy with Sword!
Enemy takes 20 damage.
Enemy attacks Hero... MISS!
Hero drinks Potion: +30 HP.
Hero shoots Boss with Bow → Boss takes 25 damage.
Boss attacks Hero... CRITICAL HIT! -40 HP.
Enemy defeated! Hero gains 10 XP.

````

---

## 🛠 Technologies

- **C++17**
- `iostream`, `vector`, `memory`, `cstdlib`, `ctime`
- OOP concepts

---

## 🚀 Compile & Run

```bash
g++ main.cpp -o rpg
./rpg
````

---

## 🔮 Future Improvements

* Add **magic spells** (fireball, healing)
* Introduce **armor/shield system**
* Implement **level-up mechanics** with skill trees
* Add **save/load feature**

---

# 🐾 Virtual Animal Game

This is a **console-based virtual pet simulator** 🐶.
You can pet, feed, and wash your animal to keep it happy.

---

## 📌 Features

* **Animal class**

  * Fields: `level`, `state`, `happiness`, `sadness`, `age`, `name`
  * Methods:

    * `food()` → list food items
    * `to_stroke()` → pet animal (+20 happiness)
    * `to_feed()` → feed animal with chosen food
    * `wash()` → wash animal (+15 happiness)
    * `update()` → update level based on happiness

* **Inheritance**

  * `your_animal` inherits from `Animal`
  * Example: Dog with pre-defined food list

---

## ▶️ Example Run

```
Welcome to Virtual Pet Game 🐾

Your animal: Dog
Available food: Bone, Meat, Fish

Action: Pet the dog
Dog feels happy! (+20 happiness)

Action: Feed dog "Meat"
Dog eats happily (+30 happiness)

Action: Wash dog
Dog looks clean and happy! (+15 happiness)

Dog leveled up! 🎉
```

---

## 🔮 Future Improvements

* Add **multiple animal types** (Cat, Rabbit, Bird)
* Introduce **mood system** (happy, sad, neutral)
* Add **save/load state**
* Implement **game loop**

---

## 🚀 Compile & Run

```bash
g++ main.cpp -o animal
./animal
```

---

# 🧮 Calculator in C++

A **command-line calculator** with extra features.

---

## 📌 Features

* Operators:

  * ➕ `+` addition
  * ➖ `-` subtraction
  * ✖️ `*` multiplication
  * ➗ `/` division (with zero check)
  * 🧮 `^` exponentiation
  * √ `s` square root

---

## ▶️ Example Runs

```
Write first number: 9
Write operator: s
Result: 3
```

```
Write first number: 5
Write operator: *
Write second number: 4
Result: 20
```

```
Write first number: 7
Write operator: /
Write second number: 0
Error: division by zero!
```

---

## 🚀 Compile & Run

```bash
g++ calculator.cpp -o calc
./calc
```

---

# 🔢 Binary Search Number Guessing

A simple guessing game using **binary search**.

---

## 📌 Features

* Range: 1–1000
* Computer guesses middle number
* If guess too high → search lower
* If guess too low → search higher
* Stops when number is found

---

## ▶️ Example Run

```
Computer guesses: 500
Too high! Trying lower...
Computer guesses: 250
Too low! Trying higher...
Computer guesses: 375
Too low! Trying higher...
Computer guesses: 460
Computer found the number 456 in 8 attempts!
```

---

## 🚀 Compile & Run

```bash
g++ algorithm.cpp -o guess
./guess
```

---

# 📂 File I/O and Struct Example

This project demonstrates **file input/output** and `struct`.

---

## 📌 Features

1. Append `"Hello World!"` to file
2. Read file line by line
3. Store points with `struct Point { x, y }`
4. Write vector of points to file
5. Read points back into vector

---

## ▶️ Example Run

```
Hello World!
Point X:0 Y:0
Point X:4 Y:5
Point X:-5 Y:7
```

---

## 📂 Code Snippet

```cpp
struct Point {
    int x, y;
};

ofstream out("text.txt", ios::app);
out << "Hello World!" << endl;

vector<Point> points{ {0,0}, {4,5}, {-5,7} };
for (auto &p : points) out << p.x << " " << p.y << endl;
```

---

## 🚀 Compile & Run

```bash
g++ fileio.cpp -o fileio
./fileio
```

---

# 📘 Detailed C++ Explanations

Since these projects are for **learning**, here are extra notes:

---

### 🔹 OOP Principles in Projects

* **Encapsulation** → Class fields (health, happiness) are private/protected
* **Inheritance** → `Hero` inherits `Character`, `your_animal` inherits `Animal`
* **Polymorphism** → Virtual methods (`attack()`, `useItem()`) work differently for each class
* **Abstraction** → Abstract base classes (`Character`, `Item`)

---

### 🔹 Smart Pointers

Instead of raw pointers:

```cpp
vector<shared_ptr<Item>> inventory;
```

This avoids **memory leaks**.

---

### 🔹 Randomness in RPG

```cpp
srand(time(0));
int damage = rand() % 20 + 1; // random damage 1–20
```

---

### 🔹 File I/O

* `ofstream` → write to file
* `ifstream` → read from file

```cpp
ofstream out("file.txt");
out << "Hello" << endl;

ifstream in("file.txt");
string line;
while (getline(in, line)) cout << line << endl;
```

---

# 📜 License

MIT License © 2025
Feel free to use, modify, and share ⭐

---

# ⭐ Final Words

This repository is a **C++ learning playground**.
It demonstrates:

* RPG mechanics ⚔️
* Virtual pets 🐾
* Calculator 🧮
* Algorithms 🔢
* File I/O 📂

Enjoy exploring, learning, and expanding 🚀
