#include <iostream>
#include <mutex>

class Singleton{
    static std::mutex mutex_;
    static Singleton* instance_;
private:
    Singleton(){};
    Singleton(const Singleton& )=delete;
    Singleton& operator=(const Singleton& ) = delete;

public:
    static Singleton* getInstance(){
        if(instance_ == nullptr){
            std::lock_guard<std::mutex> lock(mutex_);
            if(instance_ == nullptr){
                instance_ = new Singleton();
            }
        }
        return instance_;
    }

    static void destorySingleton(){
        if(instance_ != nullptr){
            delete instance_;
            instance_ = nullptr;
        }
    }
};

Singleton* Singleton::instance_ = nullptr;
std::mutex Singleton::mutex_ ;

int main(){
    Singleton *s1 = Singleton::getInstance();
    Singleton *s2 = Singleton::getInstance();
    if(s1 == s2) std::cout<<"Same instance"<<std::endl;
    Singleton::destorySingleton();
    return 0;
}