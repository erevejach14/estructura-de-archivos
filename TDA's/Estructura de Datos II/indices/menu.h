#include <iostream>

enum menuOp{};
class Menu{
  private:
    Menu();
    ~Menu();

    void showOptions;
    char selectedOption;

  public:
    void showMenu();

};

Menu::Menu{
  showMenu();
}

void Menu::showMenu(){
  char a;
  showOptions();
  a = selectedOption();
  switch (a) {
    case '1':

      break;
    case '2':

      break;

    default:
      std::cout << "Opcion invalida"
      break;
  }

}
