#ifndef PEOPLE_H
#define PEOPLE_H

#include <string>
#include <cstdlib>

#include "RussianNames.h"

class People {
private:
    std::string firstName;
    std::string lastName;
    std::string patronymic;
    std::string birthDate;
    int accountBalance;


    std::string GenerateRandomBirthDate() {
        int day = rand() % 28 + 1;         // from 1 to 28
        int month = rand() % 12 + 1;       // from 1 to 12
        int year = rand() % 60 + 1960;     // from 1960 to 2019

        char buffer[11];
        snprintf(buffer, sizeof(buffer), "%02d.%02d.%04d", day, month, year);
        return std::string(buffer);
    }

public:
    People() {
        firstName = russianFirstNames[rand() % countRussianFirstNames];
        lastName = russianLastNames[rand() % countRussianLastNames];
        patronymic = russianPatronymics[rand() % countRussianPatronymics];
        birthDate = GenerateRandomBirthDate();
        accountBalance = rand() % 1000001;
    }

    People(std::string firstName, std::string lastName, std::string patronymic, std::string birthDate, int accountBalance)
    {
        this->firstName = firstName;
        this->lastName = lastName;
        this->patronymic = patronymic;
        this->birthDate = birthDate;
        this->accountBalance = accountBalance;
    }

    bool operator<(const People& other) const
    {
        return accountBalance < other.accountBalance;
    }

    bool operator>(const People& other) const
    {
        return accountBalance > other.accountBalance;
    }

    bool operator<=(const People& other) const
    {
        return accountBalance <= other.accountBalance;
    }

    bool operator>=(const People& other) const
    {
        return accountBalance >= other.accountBalance;
    }

    bool operator==(const People& other) const
    {
        return accountBalance == other.accountBalance;
    }

    bool operator!=(const People& other) const
    {
        return accountBalance != other.accountBalance;
    }

    std::string GetFirstName()
    {
        return firstName;
    }

    std::string GetLastName()
    {
        return lastName;
    }

    std::string GetPatronymic()
    {
        return patronymic;
    }

    std::string GetBirthDate()
    {
        return birthDate;
    }

    double GetAccountBalance()
    {
        return accountBalance;
    }
};

#endif