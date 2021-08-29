#include <iostream>
#include "Valute.h"

void valuteTask();

int main() {
    setlocale(LC_ALL, "ru");

    valuteTask();
    
    return 0;
}
void valuteTask() {
    Valute valute;
    ValuteData HUF = valute.GetData("HUF");
    ValuteData NOK = valute.GetData("NOK");
    std::cout << "1 (NOK) ���������� ����� = " << HUF.CourseConclusion(NOK) << " (HUF) ���������� ��������.\n";
    std::cout << std::fixed << HUF.nominal << " ������ �� " << HUF.value << " ���������� ��������.\n";
    std::cout << std::fixed << NOK.nominal << " ������ �� " << NOK.value << " ���������� ����.\n";
}