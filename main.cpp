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
    std::cout << "1 (NOK) Норвежская Крона = " << HUF.CourseConclusion(NOK) << " (HUF) Венгерских Форинтов.\n";
    std::cout << std::fixed << HUF.nominal << " Рублей за " << HUF.value << " Венгерских Форинтов.\n";
    std::cout << std::fixed << NOK.nominal << " Рублей за " << NOK.value << " Норвежских Крон.\n";
}