  #include "cl_application.hpp"
cl_application::cl_application(cl_base * headptr) : cl_base(headptr)
{
  type = 1;
  // параметризированный конструктор
}
void cl_application::f_signal(std::string & msg)
{
  std::cout << "Signal from " << get_abs() << '\n';
  msg += " (class: 1)";
}
void cl_application::f_handler(std::string msg)
{
  std::cout << "Signal to " << get_abs() << " Text: " + msg << '\n';
}
SIGNAL_TYPE cl_application::signal_sel(cl_base * obj) // определение сигнала
{
  switch(obj->type) // через свитч
  {
  case 1:
    return SIGNAL_DEF(cl_application::f_signal);
  case 2:
    return SIGNAL_DEF(class2::f_signal);
  case 3:
    return SIGNAL_DEF(class3::f_signal);
  case 4:
    return SIGNAL_DEF(class4::f_signal);
  case 5:
    return SIGNAL_DEF(class5::f_signal);
  case 6:
    return SIGNAL_DEF(class6::f_signal);
  default:
    return nullptr;
  }
}
HANDLER_TYPE cl_application::handler_sel(cl_base * obj) // определение хендлера
{
  switch(obj->type) // через свитч
  {
  case 1:
    return HANDLER_DEF(cl_application::f_handler);
  case 2:
    return HANDLER_DEF(class2::f_handler);
  case 3:
    return HANDLER_DEF(class3::f_handler);
  case 4:
    return HANDLER_DEF(class4::f_handler);
  case 5:
    return HANDLER_DEF(class5::f_handler);
  case 6:
    return HANDLER_DEF(class6::f_handler);
  default:
    return nullptr;
  }
}
void cl_application::build_tree_objects()
{
  int i_class; // тип класса
  std::string headName, headCoords, subName; // данные для ввода
  std::cin >> headName; // ввод головы
  s_set_object_name(headName); // установка головы
  cl_base * p_head = this; // голова - текущий объект
  cl_base * p_sub = nullptr; // подчинённого объекта пока что нет
  while (std::cin >> headCoords && headCoords != "endtree") // проверка на пустой ввод и "endtree"
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
  // всё выше как в кв3. ниже для кв4
  std::string emit, t_coords; // t_coords - target coords
  while (1) // установка соединений
  {
    std::cin >> emit;
    if (emit == "end_of_connections") break;
    std::cin >> t_coords;
    cl_base * emitter = read_coords(emit);
    cl_base * target = read_coords(t_coords);
    if (emitter && target)
    {
      emitter->set_connection(signal_sel(emitter), target, handler_sel(target));
    }
  }
}
int cl_application::exec_app()
{
  set_all_state();
  std::cout << "Object tree\n";
  print();
  std::string command,s_target, s_obj;
  std::string msg {};
  int status;
  while (1)
  {
    std::cin >> command;
    if (command == "END") // завершение
    {
      break;
    }
    if (command == "EMIT") // вызов сообщения
    {
      std::cin >> s_obj;
      std::getline(std::cin,msg); // сообщение может быть любым, из-за этого работает с помощью getline
      cl_base * obj = read_coords(s_obj);
      if (obj != nullptr)
      {
        obj->emit_signal(signal_sel(obj),msg);
      }
      else
      {
        std::cout << "Object " << s_obj << " not found\n";
      }
    }
    else if (command == "SET_CONNECT") // установка соединения
    {
      std::cin >> s_obj >> s_target;
      cl_base * obj = read_coords(s_obj);
      cl_base * target = read_coords(s_target);
      if (obj && target)
      {
        obj->set_connection(signal_sel(obj), target, handler_sel(target));
      }
      else if (!obj)
      {
        std::cout << "Object " << s_obj << " not found\n";
      }
      else if (!target)
      {
        std::cout << "Handler object " << s_obj << " not found\n";
      }
    }
    else if (command == "DELETE_CONNECT") // удаление соединения
    {
      std::cin >> s_obj >> s_target;
      cl_base * obj = read_coords(s_obj);
      cl_base * target = read_coords(s_target);
      if (obj && target)
      {
        obj->delete_connection(signal_sel(obj), target, handler_sel(target));
      }
      else if (!obj)
      {
        std::cout << "Object " << s_obj << " not found\n";
      }
      else if (!target)
      {
        std::cout << "Handler object " << s_obj << " not found\n";
      }
    }
    else if (command == "SET_CONDITION") // установка состояния
    {
      std::cin >> s_obj >> status;
      cl_base * obj = read_coords(s_obj);
      if (obj)
      {
        obj->set_obj_state(status);
      }
      else
      {
        std::cout << "Object " << s_obj << " not found\n";
      }
    }
  }
  return 1;
}
