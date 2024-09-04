#include "cl_application.hpp"
cl_application::cl_application(cl_base * headptr) : cl_base(headptr)
{
// параметризированный конструктор
}
void cl_application::build_tree_objects()
{
  cl_base * p_head; // указатель головы
  cl_base * p_sub = this; // указатель - последний добавленный
  std::string s_head, s_sub; // строковые головы и подчинённых
  int i_class, i_state; // целочисленный вид класса и состояние
  std::cin >> s_head; // ввод значения головы
  this->s_set_object_name(s_head); // поставить новое имя для текущего объекта
  p_head = this; // текущий объект = головной
  while(1) // бесконечный цикл
  {
    std::cin >> s_head; // ввод нового имени
    if (s_head == "endtree") break; // оборвать бесконечный цикл
    std::cin >> s_sub >> i_class; // ввод значений
    p_head = p_sub->p_get_tree(s_head); // присвоить голове результат работы p_get_tree у p_sub, последнего объекта
    if (p_head == nullptr && p_get_tree(s_sub) != nullptr) continue; // если головной объект нулевой (то есть не существует), но результат работы p_get_tree с параметром подчинённого не нулевой , возвращаемся в начало цикла
    switch(i_class) // Оператор витвления. Использовать оператор витвления switch по значению переменной i_class
    {
      case 2: // создание объектов в зависимости от числа
        p_sub = new class2(p_head,s_sub);
        break;
      case 3:
        p_sub = new class3(p_head,s_sub);
        break;
      case 4:
        p_sub = new class4(p_head,s_sub);
        break;
      case 5:
        p_sub = new class5(p_head,s_sub);
        break;
      case 6:
        p_sub = new class6(p_head,s_sub);
        break;
    }
  }
  while (std::cin >> s_sub) // ввод состояния
  {
    std::cin >> i_state;
    p_sub = p_get_tree(s_sub);
    if (p_sub != nullptr) p_sub->set_obj_state(i_state); // если существует, то поставить значение состояния
  }
}
int cl_application::exec_app()
{
  std::cout << "Object tree\n";
  print_branch(); // вывод дерева
  std::cout << "The tree of objects and their readiness\n";
  print_branch_state(); // вывод состояния дерева
  return 1;
}
