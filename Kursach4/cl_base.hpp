#ifndef __CL_BASE__H
#define __CL_BASE__H
#include <string>
#include <vector>
#include <iostream>
#include <queue>
// кв4, сигнал
class cl_base; // чтобы не жаловалось мы создадим пустой класс, а потом его распишем
typedef void(cl_base::*SIGNAL_TYPE)(std::string& msg);
// SIGNAL - Сигнал
// typedef - директива type define
// void - ничего не возвращает
// cl_base::*SIGNAL_TYPE - указатель на метод из cl_base
// std::string & msg - адрес на строковое поле msg, сообщение
typedef void(cl_base::*HANDLER_TYPE)(std::string msg);
// HANDLER - Обработчик
// std::string msg - Параметр строкового
#define SIGNAL_DEF(f_signal) (SIGNAL_TYPE)(&f_signal) // Чтобы не писать тонну текста, нужен define.
// Он избавит нас от приведения к типу
#define HANDLER_DEF(f_handler) (HANDLER_TYPE)(&f_handler)
// Пример вызова без define ниже!
// p_obj->set_connection((SIGNAL_TYPE)&class2::f_signal, target, (HANDLER_TYPE)&class2::f_handler)
// С define
// p_obj->set_connection(SIGNAL_DEF(class2::f_signal),target,HANDLER_DEF(class2::f_handler)
struct o_sh
{
  SIGNAL_TYPE signal;
  cl_base * target;
  HANDLER_TYPE handler;
};

class cl_base
{
  private:
  std::string s_object_name;
  cl_base * p_head_object;
  std::vector <cl_base*> subordinate_objects;
  // кв3
  int state = 0;
  // кв4
  std::vector<o_sh *> connections; // Соединения
  public:
    /* для кв4 -> */ int type;
  cl_base(cl_base* headptr, std::string name = "Base_object",int type = 0); // Конструктор
  ~cl_base(); // Деструктор
  // кв1
  bool s_set_object_name(std::string name);
  std::string s_get_object_name();
  cl_base * p_get_head_object();
  cl_base * p_get_object_by_name(std::string name);
  // void print_sub -> устаревший
  // кв2
  cl_base * p_get_branch(std::string target);
  cl_base * p_get_tree(std::string target);
  void set_obj_state(int new_state);
  void print(); // в кв3 одинаков
  void print_state(); // в кв3 одинаков, но не используется
  // кв3
  bool change_head_pointer(cl_base * newptr);
  void delete_sub_obj(std::string s_name);
  cl_base * read_coords(std::string coords); // find obj by coordinates/coords
  // кв4
  void set_connection(SIGNAL_TYPE signal, cl_base * target, HANDLER_TYPE handler);
  void delete_connection(SIGNAL_TYPE signal, cl_base * target, HANDLER_TYPE handler);
  void emit_signal(SIGNAL_TYPE signal, std::string message);
  std::string get_abs();
  void set_all_state();
};
#endif
