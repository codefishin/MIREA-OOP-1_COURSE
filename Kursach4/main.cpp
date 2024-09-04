#include <stdlib.h>
#include <stdio.h>
#include "cl_application.hpp"
int main()
{
  cl_application ob_cl_application ( nullptr ); // создание объекта приложение
  ob_cl_application.build_tree_objects ( ); // конструирование системы,
  return ob_cl_application.exec_app ( ); // запуск системы
}
