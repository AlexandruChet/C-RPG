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
