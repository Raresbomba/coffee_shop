#ifndef OOP_PRODUCTFACTORY_HPP
#define OOP_PRODUCTFACTORY_HPP
#include <memory>
#include "Product.hpp"


class ProductFactory {
    public:
    virtual ~ProductFactory() = default;
    virtual std::unique_ptr<Product> createProduct(const std::string& name) = 0;
};

#endif //OOP_PRODUCTFACTORY_HPP