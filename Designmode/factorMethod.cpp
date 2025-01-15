#include <iostream>
#include <cstring>
#include <memory>

class Product{
public:
    virtual ~Product(){}
    virtual void run() = 0;
};

class ProductA : public Product{
public:
    virtual void run() override{
        std::cout<<"ProductA run "<<std::endl;
    }
};

class ProductB : public Product{
public:
    virtual void run() override{
        std::cout<<"ProductB run "<<std::endl;
    }
};

class Factory{
public:
    virtual ~Factory(){}
    virtual std::unique_ptr<Product> createProduce() = 0; 
};

class ConcreteFactoryA: public Factory{
public:
    virtual std::unique_ptr<Product> createProduce() override{
        return std::make_unique<ProductA>();
    }
};

class ConcreteFactoryB: public Factory{
public:
    virtual std::unique_ptr<Product> createProduce() override{
        return std::make_unique<ProductB>();
    }
};

int main(){
    std::unique_ptr<Factory> factorya = std::make_unique<ConcreteFactoryA>();
    std::unique_ptr<Product> producta(factorya->createProduce());
    producta->run();
    std::unique_ptr<Factory> factoryb = std::make_unique<ConcreteFactoryB>();
    std::unique_ptr<Product> productb(factoryb->createProduce());
    productb->run();
    return 0;
}