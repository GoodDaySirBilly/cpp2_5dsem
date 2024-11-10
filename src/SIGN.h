//
// Created by user on 11/10/2024.
//

#ifndef CPP2_5DSEM_SIGN_H
#define CPP2_5DSEM_SIGN_H
#include <string>
#include <iostream>

class SIGN {
private:
    std::string name,surname;
    std::string zodiac;
    int birthday[3];
public:
    explicit SIGN(const std::string &name,const std::string &surname,const std::string &zodiac, int[3]);
    explicit SIGN(const std::string& n);
    explicit SIGN();
    SIGN(const SIGN& another);
    virtual ~SIGN();


    const std::string &getName() const;

    void setName(const std::string &name);

    const std::string &getSurname() const;

    void setSurname(const std::string &surname);

    const std::string &getZodiac() const;

    void setZodiac(const std::string &zodiac);

    const int *getBirthday() const;

    void setBirthday(const int *);


    std::ostream &operator<<(std::ostream& os);
};


#endif //CPP2_5DSEM_SIGN_H
