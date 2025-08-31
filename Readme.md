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
