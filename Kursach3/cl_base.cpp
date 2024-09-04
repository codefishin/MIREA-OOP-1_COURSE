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
// new methods (KV3)
cl_base * cl_base::read_coords(std::string coords)
{
  if (coords.empty()) return nullptr; // если никаких координат не было передано
  cl_base * temp = this; // временный указатель
  if (coords[0] == '.')
  {
    if (coords == ".")
    {
      return temp; // проверка на . (текущий объект)
    }
    coords.erase(0,1); // Не то что нам нужно (не текущий), стереть первую точку
    return temp->p_get_branch(coords); // вернуть поиск по ветке (поиск от текущего, по типу .obj1)
  }
  else if (coords[0] == '/') // иначе от головы
  {
    while (temp->p_get_head_object())
    temp = temp->p_get_head_object(); // поднимаеся до головы
    if (coords == "/") return temp; // если был только один /, то просят голову
    if (coords[1] == '/') // если второй символ /
    {
      coords.erase(0,2); // стереть первые два символа
      return temp->p_get_tree(coords); // искать от головы значение координат
    }
    coords.erase(0,1); // ничто не подошло, стереть первый символ
  }
  std::string tempname {}; // инициализация, чтоб не багнулось
  for (int i = 0; i < coords.length(); i++) // пробегает все символы
  {
    if (coords[i] == '/') // если нашёлся /
    {
      temp = temp->p_get_object_by_name(tempname); // начать поиск
      if (!temp) return temp; // если нулевой, вернуть значение temp
      tempname = ""; // очистить имя искомого
    }
    else
    {
      tempname += coords[i]; // пополнять имя искомого.
    }
  }
  return temp->p_get_object_by_name(tempname); // вернуть поиск по имени
}
void cl_base::delete_sub_obj(std::string s_name)
{
  /*
  Удаление объекта по имени, s_name - искомое имя объекта, которое нужно
  удалить
  */
  cl_base * temp = p_get_object_by_name(s_name); // поиск подчинённого
  if (temp) // если подчинённый нашёлся
  {
    cl_base * p_head = temp->p_get_head_object(); // голова
    for (int i = 0; i < p_head->subordinate_objects.size(); i++) // поиск
    {
      if (p_head->subordinate_objects[i] == temp) // нашёлся удаляемый объект
      {
        p_head->subordinate_objects.erase(p_head->subordinate_objects.begin() + i); // удалить его из списка подчинённых
      delete temp;
      break;
      }
    }
  }
}
bool cl_base::change_head_pointer(cl_base * newptr)
{
  if (!newptr) return false; // если параметр нулевой
  if (!this->p_head_object) return false; // если нет головы
  if (newptr->p_get_object_by_name(this->s_get_object_name())) return false; // если дубликат
  cl_base * temp = newptr; // временный указатель
  while(temp != nullptr) // пока не нулевой
  if (temp == this)
  {
    return false; // если текущий
  }
  else
  {
    temp = temp->p_get_head_object(); // поднимаемся по головам
  }
  temp = this->p_head_object; // присваиваем временному значение головы
  for (int i = 0; i < temp->subordinate_objects.size(); i++) // поиск
  {
    if (temp->subordinate_objects[i] == this) // нашёлся новый головной
    {
      temp->subordinate_objects.erase(temp->subordinate_objects.begin() + i); // убрать его из подчинённых. он больше не подчиняется
      break;
    }
  }
  this->p_head_object = newptr; // новый головной указатель
  newptr->subordinate_objects.push_back(this); // старый головной уходит к подчинённым
  return true; // отработало верно
}
void cl_base::print() // вывод ветки
{
  static int index = 0; // вместо параметра пришлось ставить вот эту глобальную переменную index
  if (index == 0) std::cout << this->s_get_object_name() << "\n"; // для самого первого раза, чтобы правильно выводилось
  index++; // увеличить наш "параметр"
  for (auto current : subordinate_objects) // цикл который перебирает все подчинённые объекты
  {
    for (int space = 0; space < index * 4; space++) std::cout << " "; // цикл для вывода пробелов
    std::cout << current->s_get_object_name() << "\n"; // получение имени объекта
    current->print(); // рекурсионный вызов
  }
  index--; // уменьшить наш "параметр"
}
void cl_base::print_state()
{
  std::string s_state = ""; // строковое значение состояния
  static int index2 = 0; // вместо параметра пришлось ставить вот эту глобальную переменную index
  if (index2 == 0)
  {
    if (this->state != 0) // если вкл
    {
      s_state = " is ready"; // вкл
    }
    else // если откл
    {
      s_state = " is not ready"; // откл
    }
    std::cout << this->s_get_object_name() << s_state << "\n"; // для самого первого раза, чтобы правильно выводилось
  }
  index2++; // увеличить наш "параметр"
  for (auto current : subordinate_objects) // цикл который перебирает все подчинённые объекты
  {
    for (int space = 0; space < index2 * 4; space++) std::cout << " "; // цикл для вывода пробелов
    if (current->state != 0)
    {
      s_state = " is ready";
    }
    else
    {
      s_state = " is not ready";
    }
    std::cout << current->s_get_object_name() << "\n"; // получение имени объекта
    current->print(); // рекурсионный вызов
  }
  index2--; // уменьшить наш "параметр"
}
cl_base::~cl_base()
{
  // destructor
  subordinate_objects.clear(); // очистка подчинённых объектов
}
