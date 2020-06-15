#ifndef DTO_H
#define DTO_H

#include <string>
#include <vector>
#include <memory>

#include <odb/core.hxx>

#pragma db object session
class DNA
{
public:
    DNA() {
        _id = 0;
    };

    unsigned long id() const {
        return _id;
    }

    void id(unsigned long value) {
        _id = value;
    }

    void chain(const std::string &value) {
        _chain = value;
    }

    std::string chain() const {
        return _chain;
    }

    void isMustant(bool value) {
        _isMutant = value;
    }

    bool isMutant() const {
        return _isMutant;
    }

private:
    friend class odb::access;

#pragma db id auto
    unsigned long _id;

    std::string _chain;
    bool _isMutant;

};


#pragma db view object(DNA)
struct DNA_count
{
#pragma db column("count(1)")
    std::size_t count;
};

#endif // DTO_H
