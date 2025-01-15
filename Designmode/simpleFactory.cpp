#include <iostream>
#include <cstring>
#include <memory>

class Product{
public:
    virtual ~Product(){};
    virtual void run() = 0;
};

class ProductA : public Product{
public:
    void run () override{
        std::cout<<"ProductA run "<<std::endl;
    }
};

class ProductB : public Product{
public:
    void run () override{
        std::cout<<"ProductB run "<<std::endl;
    }
};

class SimpleFactory{
public:
    static std::unique_ptr<Product> createProduce(std::string type){
        if(type == "A"){
            return  std::make_unique<ProductA>();
        }else if(type == "B"){
            return  std::make_unique<ProductB>();
        }else{
            return nullptr;
        }
    }
};


int main(){
    std::unique_ptr<Product> producta(SimpleFactory::createProduce("A"));
    std::unique_ptr<Product> productb(SimpleFactory::createProduce("B"));
    producta->run();
    productb->run();
    return 0;
}