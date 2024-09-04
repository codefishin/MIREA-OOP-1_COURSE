  #include "cl_application.hpp"
cl_application::cl_application(cl_base * headptr) : cl_base(headptr)
{
  // параметризированный конструктор
}
void cl_application::build_tree_objects()
{
  int i_class; // тип класса
  std::string headName, headCoords, subName; // данные для ввода
  std::cin >> headName; // ввод головы
  s_set_object_name(headName); // установка головы
  cl_base * p_head = this; // голова - текущий объект
  cl_base * p_sub = nullptr; // подчинённого объекта пока что нет
  while (std::cin >> headCoords && headCoords != "endtree") // проверка на пустой ввод или "endtree"
  {
    std::cin >> subName >> i_class; // ввод информации об объекте
    p_head = p_head->read_coords(headCoords); // голова находится через координаты
    if (!p_head) // если головы нет
    {
      // аварийная проверка, вывод дерева
      std::cout << "Object tree\n";
      print();
      std::cout << "The head object " << headCoords << " is not found\n";
      exit(1); // аварийный выход. exit(0) - выход без ошибок, exit(1) - выход с ошибкой
      // вызов функции exit, которая завершает программу, в которую передаём 1 (Аварийная ошибка)
    }
    if (p_head->p_get_object_by_name(subName)) // если в подчиённых нашлись дубликаты
    {
      std::cout << headCoords << " Dubbing the names of subordinate objects\n";
    }
    else
    {
      switch(i_class) // создание объектов
      {
        case 2:
          p_sub = new class2(p_head,subName);
          break;
        case 3:
          p_sub = new class3(p_head,subName);
          break;
        case 4:
          p_sub = new class4(p_head,subName);
          break;
        case 5:
          p_sub = new class5(p_head,subName);
          break;
        case 6:
          p_sub = new class6(p_head,subName);
        break;
      }
    }
  }
}
int cl_application::exec_app()
{
  std::cout << "Object tree\n"; // вывод дерева
  print(); // вывод дерева
  std::string s_command, s_coords; // команда и координаты. Координаты необязательно хранят координаты
  // по-хорошему надо было назвать s_input, а не s_coords. :>
  cl_base * p_cur = this; // текущий объект
  cl_base * p_found = this; // найденный объект
  while (1)
  {
    std::cin >> s_command; // ввод команды
    if (s_command == "END" || s_coords == "END") break; // если команда (или координата) просят завершение
// ^ то завершить программу. ^
    std::cin >> s_coords; // ввод координат
    if (s_command == "SET") // если установка текущего объекта
    {
      if (p_cur->read_coords(s_coords) != nullptr) // если можно установить (он существует)
      {
        p_cur = p_cur->read_coords(s_coords); // установить новый текущий объект
        std::cout << "Object is set: " << p_cur->s_get_object_name() << '\n';
        // передать пользователю информацию, о том что новый текущий установлен
      }
      else // иначе такого объекта нет
      {
// передать пользователю информацию об ошибке
      std::cout << "The object was not found at the specified coordinate: " << s_coords << '\n';
      }
  }
  if (s_command == "FIND") // если объект хотят найти
  {
    if (p_cur->read_coords(s_coords) != nullptr) // если можно найти (он существует)
    {
      p_found = p_cur->read_coords(s_coords); // присвоить найденному объекту значение искомого
      std::cout << s_coords << " Object name: " << p_found->s_get_object_name() << '\n'; // передать пользователю информацию, что объект найден
    }
    else
    {
      // передать пользователю информацию об ошибке
      std::cout << s_coords << " Object is not found\n";
    }
  }
  if (s_command == "MOVE") // если пользователь хочет поменять головной объект
  {
    cl_base * temp = this->read_coords(s_coords); // временный указатель, который ищет координату и хранит информацию
    if (!temp) // не нашлось
    {
      std::cout << s_coords << " Redefining the head object failed\n";
    }
    else if (temp->p_get_object_by_name(p_cur->s_get_object_name())) //дубликат
    {
      std::cout << s_coords << " Dubbing the names of subordinate objects\n";
    }
    else if (!p_cur->change_head_pointer(temp)) // нельзя поменять (см. метод)
    {
      std::cout << s_coords << " Redefining the head object failed\n";
    }
    else if (p_get_tree(temp->p_get_head_object()->s_get_object_name()) == nullptr) // не нашлось головы
    {
      std::cout << s_coords << " Head object is not found\n";
    }
    else // всё хорошо.
    {
      std::cout << "New head object: " << temp->s_get_object_name() << "\n";
    }
  }  
  if (s_command == "DELETE")
  {
    std::string s_abs = ""; // абсолютная координата
    cl_base * temp = p_cur->p_get_object_by_name(s_coords); // содержит информацию о найденном объекте среди подчинённых текущего
    if (temp == nullptr) // объекта нет, перейти в начало цикла
    {
      continue;
    }
    while (temp->p_get_head_object() != nullptr) // цикл, который доходит до головы
    {
      s_abs = '/' + temp->s_get_object_name() + s_abs; // создание абсолютного пути
      temp = temp->p_get_head_object(); // идём дальше по головам
    }
    p_cur->delete_sub_obj(s_coords); // удаление объекта
    if (p_cur->p_get_object_by_name(s_coords) == nullptr) // если объект удалился
    {
      std::cout << "The object " << s_abs << " has been deleted\n"; // сказать,что он удалился
    }
  }
}
 std::cout << "Current object hierarchy tree\n";
 print(); // вывод нового дерева
 return 1;
}
