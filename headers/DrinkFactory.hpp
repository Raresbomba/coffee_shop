#ifndef OOP_FACTORY_HPP
#define OOP_FACTORY_HPP
#include <memory>
#include "Product.hpp"
#include "ProductFactory.hpp"

class DrinkFactory final : public ProductFactory {
public:
     std::unique_ptr<Product> createProduct(const std::string& name) override;
};

#endif //OOP_FACTORY_HPP