#include "Record.h"

int main()
{
    Record a; //Конструктор за замовчуванням

    Record b("Iskorostenskyi M", "+38-099-00-01-001", "Kharkiv",
        "mykola@itstep.academy"); //Конструктор з параметрами

    a.showInfo();
    b.showInfo();

    cout << "+++++++++++++++++++++++++++++++\n\n";
    a.setName(""); // Error
    a.setName("Levchenko Y");
    b.setAddress("Bezlyudovka");
    cout << endl;
    cout << a.getName() << " lives in " << a.getAddress() << endl;
    cout << b.getName() << " lives in " << b.getAddress() << endl;
    cout << "+++++++++++++++++++++++++++++++\n\n";

    a.addPhoneNumber("057-01-001-01");
    a.addPhoneNumber("12-45");
    a.addPhoneNumber("+38(097) 34-23-122");

    b.addPhoneNumber("45-782");

    a.showInfo();
    b.showInfo();
}
