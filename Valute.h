#pragma once
#ifndef VALUTE_H
#define VALUTE_H

#include "Client.h"
#include "ValuteData.h"

class Valute {
public:
    ValuteData GetData(std::string valuteCode) {
        ValuteData data;
        Client client;
        std::string sourceHTML = client.getResponse("XML_daily.asp");
        data.nominal = GetNominal(sourceHTML, valuteCode);
        data.value = GetValue(sourceHTML, valuteCode);
        std::cout << data.value << std::endl;
        data.course = data.nominal / data.value;
        return data;
    }
private:
    double GetValue(std::string& sourceHTML, std::string valuteCode) {
        double tempDouble;
        std::string tempString = GetValueWithComma(sourceHTML, valuteCode);
        CommaToDot(tempString);
        stringstream str;
        str << tempString;
        str >> tempDouble;
        return tempDouble;
    }
    int GetNominal(std::string& sourceHTML, std::string valuteCode) {
        unsigned int firstValuteIndex = sourceHTML.find(valuteCode);

        std::string buffer = "";
        for (unsigned int i = firstValuteIndex; i < sourceHTML.size(); i++) {
            buffer = buffer + sourceHTML[i];
            if (sourceHTML.substr(i + 1, 10) == "</Nomainal>") { break; }
        }
        return std::stoi(buffer.substr(buffer.find("<Nominal>") + 9, buffer.length()));
    }
    std::string GetValueWithComma(std::string& sourceHTML, std::string valuteCode) {
        unsigned int firstValuteIndex = sourceHTML.find(valuteCode);

        std::string buffer = "";
        for (unsigned int i = firstValuteIndex; i <= sourceHTML.size(); i++) {
            buffer = buffer + sourceHTML[i];
            if (sourceHTML.substr(i + 1, 8) == "</Value>") { break; }
        }
        return buffer.substr(buffer.find("<Value>") + 7, buffer.length());
    }
    void CommaToDot(std::string &valueString) {
        for (unsigned int i = 0; i <= valueString.length(); i++) {
            if (valueString[i] == ',') {
                valueString[i] = '.';
                break;
            }
        }
    }
};

#endif