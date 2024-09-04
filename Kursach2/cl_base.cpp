#include "cl_base.hpp"
cl_base::cl_base(cl_base* headptr, std::string name)
{
  p_head_object = headptr; // Указатель на головной объект
  s_object_name = name; // Наименование объекта
  if ( p_head_object )
  {
    p_head_object -> subordinate_objects.push_back ( this ); // добавление в состав подчиненных головного объекта
  }
}
bool cl_base::s_set_object_name(std::string name)
{
  if(p_head_object == nullptr) // Условие на проверку нулевого указателя. Если вставить позже, программа крашнется
  {
    s_object_name = name; // присвоить новое название объекту
    return true; // вернуть "да", так как успешно присвоили объекту имя
  }
  if(p_head_object->p_get_object_by_name(name) == nullptr) // условие, чтобыголовной указатель не имел имени
  {
    s_object_name = name;
    return true;
  }
  return false;
}
std::string cl_base::s_get_object_name() // метод для получения имени
{
  return s_object_name; // возвращает имя объекта
}
cl_base * cl_base::p_get_head_object() // получение указателя
{
  return p_head_object; // вернуть указатель объекта
}
cl_base * cl_base::p_get_object_by_name(std::string name) // метод поиска объекта
{
  for(int i = 0; i < subordinate_objects.size();i++) // цикл прогоняющий весь вектор подчинённых объектов
  {
    if (subordinate_objects[i]->s_get_object_name() == name) // условие, которое отвечает за то, что если один из подчинённых объект вернул название, похожее на параметр ...
    {
      return subordinate_objects[i]; // вернуть найденный объект
    }
  }
  return nullptr; // ничего не нашлось, вернуть нулевой указатель
}
cl_base * cl_base::p_get_branch(std::string name)
{
  std::queue<cl_base *> q; // очередь q
  cl_base * temp = nullptr; // временный указатель
  q.push(this); // внедрить в очередь текущий объект
  while (!q.empty()) // если очередь не пустая
  {
    cl_base * front = q.front(); // задать новый указатель, который будет первым элементом очереди
    q.pop(); // выкинуть первый элемент очереди
    if(front->s_get_object_name() == name) // если первый элемент равен параметру name, который мы ищем
    {
      if (temp == nullptr) temp = front; // если temp, временный указатель, который мы должны найти, нулевой, то присвоить значение первого элемента очереди
      else return nullptr; // иначе он не уникален, вернуть нулевой указатель
    }
    for (auto current : front->subordinate_objects) // пробег всех объектов
    {
      q.push(current); // добавить итератор внутрь очереди
    }
  }
  return temp; // вернуть найденный/временный указатель
}
cl_base * cl_base::p_get_tree(std::string target)
{
  cl_base * temp = this;
  while (temp->p_get_head_object() != nullptr) temp = temp->p_get_head_object(); // цикл который смотрит до того момента, пока не дойдёт до нулевого указателя и присваивает временному указателю результат работы метода p_get_head_object
  return temp->p_get_branch(target); // вернуть результат работы метода p_get_branch
}
void cl_base::print_branch() // вывод ветки
{
  static int index = 0; // вместо параметра пришлось ставить вот эту глобальную переменную index
  if (index == 0) std::cout << this->s_get_object_name() << "\n"; // для самого первого раза, чтобы правильно выводилось
  index++; // увеличить наш "параметр"
  for (auto current : subordinate_objects) // цикл который перебирает все подчинённые объекты
  {
  for (int space = 0; space < index * 4; space++) std::cout << " "; // цикл для вывода пробелов
  std::cout << current->s_get_object_name() << "\n"; // получение имени объекта
  current->print_branch(); // рекурсионный вызов
  }
  index--; // уменьшить наш "параметр"
}
void cl_base::print_branch_state()
{
  static int indexstate = 0; // вместо параметра пришлось ставить вот эту глобальную переменную indexstate
  std::string objectstate; // строковая, которая отвечает за вкл/откл
  if (indexstate == 0) // для первого объекта
  {
    if (this->state != 0) // проверка на готовность
    {  
      objectstate = " is ready"; // вкл
    }
    else
    {
      objectstate = " is not ready"; // откл
    }
    std::cout << this->s_get_object_name() << objectstate << "\n"; // вывести состояние текущего объекта
  }
  indexstate++; // увеличить наш "параметр"
  for (auto current : subordinate_objects)
  {
    for (int space = 0; space < indexstate * 4; space++) std::cout << " ";
    if (current->state != 0) // проверка на вкл/откл
    {
      objectstate = " is ready"; // вкл
    }
    else
    {
      objectstate = " is not ready"; // откл
    }
    std::cout << current->s_get_object_name() << objectstate << "\n"; //вывод состояния прочих объектов
    current->print_branch_state(); // рекурсионный вызов
  }
  indexstate--; // уменьшить наш "параметр"
}
void cl_base::set_obj_state(int new_state)
{
  cl_base * temp = this; // временный указатель
  while (temp->p_get_head_object() != nullptr) // цикл, который активен до того, пока не найдёт нулевой указатель
  {
    if (temp->p_get_head_object()->state == 0) new_state = false; // нужно для того, чтобы объекты ниже были отключены
    temp = temp->p_get_head_object(); // получить головной указатель
  }
  if (new_state == 0) // если новое состояние откл
  {
    state = 0; // поставить откл
    for (auto current : subordinate_objects) // пробегает все подчинённые
    {
      current->set_obj_state(0); // поставить всё на откл
    }
  }
  else state = new_state; // иначе ставим значение нашего параметра
}
