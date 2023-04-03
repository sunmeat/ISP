#include <iostream>
#include <string>
using namespace std;

// Базовый класс для всех животных
class Animal {
    virtual bool isAlive() = 0;
    virtual int getEnergy() = 0;
    virtual string getName() = 0;
};

// Интерфейс для животных, которые могут летать
__interface IFlyable {
    void fly();
};

// Интерфейс для животных, которые могут плавать
__interface ISwimmable {
    void swim();
};

// Интерфейс для животных, которые могут издавать звуки
__interface ISpeakable {
    void speak();
};

// Класс кошки, реализующий интерфейс ISpeakable
class Cat : /* public Animal, */ public ISpeakable {
public:
    void speak() {
        cout << "Мяу!\n";
    }
};

// Класс собаки, реализующий интерфейсы ISwimmable и ISpeakable
class Dog : /* public Animal, */ public ISwimmable, public ISpeakable {
public:
    void swim() {
        cout << "Плыву по-собачьи!\n";
    }
    void speak() {
        cout << "Гав-гав!\n";
    }
};

// Класс птицы, реализующий интерфейсы IFlyable и ISpeakable
class Bird : /* public Animal, */ public IFlyable, public ISpeakable {
public:
    void fly() {
        cout << "Я лечу!\n";
    }
    void speak() {
        cout << "Чик-чирик!\n";
    }
};

// Класс рыбы, реализующий интерфейс ISwimmable
class Fish : /* public Animal, */ public ISwimmable {
public:
    void swim() {
        cout << "Плыву в воде!\n";
    }
};

int main() {
    setlocale(0, "");
    // Создание объектов и вызов их методов
    Cat cat;
    cat.speak();

    Dog dog;
    dog.swim();
    dog.speak();

    Bird bird;
    bird.fly();
    bird.speak();

    Fish fish;
    fish.swim();
}

/*
Задание: создать интерфейс для класса животных, который
реализует принцип Interface Segregation Principle.

Создайте интерфейс с именем Animal, который будет иметь методы,
относящиеся к животным. Например, интерфейс может содержать
методы isAlive(), getEnergy() и getName().

Создайте несколько классов, которые будут реализовывать этот
интерфейс. Каждый класс будет представлять различный вид
животного, например, класс Cat, Dog, Bird, Fish и т.д.

Разбейте интерфейс на более мелкие интерфейсы, чтобы
соответствовать принципу Interface Segregation Principle.
Например, вы можете создать интерфейсы IFlyable, ISwimmable,
ISpeakable, которые будут включены в основной интерфейс Animal.
Классы животных могут теперь реализовывать только те интерфейсы,
которые соответствуют их специфическим потребностям.

Обновите классы животных, чтобы они реализовывали только те
интерфейсы, которые им необходимы. Например, класс Cat будет
реализовывать только интерфейсы ISpeakable, а класс Fish будет
реализовывать только интерфейс ISwimmable.

Напишите тесты для проверки работоспособности кода.

Это задание демонстрирует, как использование принципа
Interface Segregation может помочь создавать более гибкий и
расширяемый код. Разбиение интерфейса на более мелкие
интерфейсы позволяет классам реализовывать только те методы,
которые им нужны, что повышает модульность и улучшает
переиспользование кода.

===========================================================

В данном коде реализован принцип Interface Segregation Principle
(ISP) - разделения интерфейсов. Вместо создания одного
интерфейса Animal, содержащего все возможные методы для животных,
были созданы более специализированные интерфейсы IFlyable,
ISwimmable и ISpeakable, которые описывают только те функции,
которые должны быть реализованы классами, способными летать,
плавать и издавать звуки соответственно.

Таким образом, классы-наследники реализуют только те методы,
которые им нужны, и не обязаны реализовывать ненужные методы,
что снижает связность между классами и делает код более гибким
и расширяемым.
*/

// BAD EXAMPLE: https://gist.github.com/sunmeat/bc829ddad45261695fcb9a1c189921cb
// GOOD EXAMPLE: https://gist.github.com/sunmeat/6eacb206150ced7ea786cbf7ba792c67
