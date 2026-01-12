//
// Created by zzrar on 1/12/2026.
//

#ifndef OOP_DESSERTFACTORY_HPP
#define OOP_DESSERTFACTORY_HPP
#include "ProductFactory.hpp"
#include "Product.hpp"
#include <memory>

class DessertFactory final : public ProductFactory {
    public:
    std::unique_ptr<Product> createProduct(const std::string& name) override;
};


#endif //OOP_DESSERTFACTORY_HPP