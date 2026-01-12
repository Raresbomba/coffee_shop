#ifndef OOP_FACTORY_HPP
#define OOP_FACTORY_HPP
#include <memory>
#include "Product.hpp"


class Factory {
public:
    static std::unique_ptr<Product> createProduct(const std::string& name);
};

#endif //OOP_FACTORY_HPP