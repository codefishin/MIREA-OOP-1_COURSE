#ifndef __MYCLASS__H
#define __MYCLASS__H
class MyClass
{
private:
  int i_private;
  void changevalueprivate();
public:
  int i_public;
  MyClass(int i_data);
  void print();
  void summon();
  void changevalue();
};
#endif
