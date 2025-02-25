#ifndef __MYCLASS__H
#define __MYCLASS__H
#include <iostream>
class MyClass
{
private:
  int * myarray;
  int size;
public:
  MyClass(); // Конструктор
  MyClass(int size); // Параметризированный конструктор
  MyClass(const MyClass & obj); // Конструктор копирования
  ~MyClass(); // Деструктор
  void input(); // Ввод. Мне не даёт отправить задание из-за неверной постановки переменной.
  void createArray(); // Инициализация массива
  void printArray(); // Вывод массива
  int getSum(); // Метод возвращения общей суммы всех элементов массива
  void method1(); // Метод 1
  void method2(); // Метод 2
};
#endif
