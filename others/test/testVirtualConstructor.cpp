#include <iostream>
#include <string>
#include <typeinfo>
#include <list>

using namespace std;

class Animal {
public:
    Animal():name("a"),age(1){}
    Animal(const string &str, const int &n):name(str), age(n){}

    virtual void yell(){
        cout << "Animal yell" << endl;
    }
    virtual ~Animal(){}
    virtual Animal* clone() const{
        return new Animal(*this);
    }

protected:
    string name;
    int age;

};

class Cat: public Animal {
public:
    static int num;
    Cat(){
        ++num;
    }
    Cat(const string &str, const int &n):Animal(str,n){
        ++num;
    }

    virtual ~Cat(){
        --num;
    }
    virtual Cat* clone() const{
        cout << "clone Cat" << endl; 
        return new Cat(*this);
    }

    virtual void yell(){
        cout << "Miao, Miao, I am " << name << endl; 
    }

    static int getNum(){
        return num;
    }

private:
    

};

class Dog: public Animal {
public:
    static int num;
    Dog(){
        ++num;
    }
    Dog(const string &str, const int &n):Animal(str,n){
        ++num;
    }

    virtual ~Dog(){
        --num;
    }

    virtual Dog* clone() const{
        cout << "clone Dog" << endl;
        return new Dog(*this);
    }

    virtual void yell(){
        cout << "Wang, Wang, I am " << name << endl;
    }

    static int getNum(){
        return num;
    }

private:
    

};

//Use "virtual constructor" to add animals to the Zoo
class Zoo {
public:
    Zoo(){}
    Zoo(const Zoo &rhs){
        for (list<Animal*>::const_iterator it = rhs.zooAnimal.begin(); it != rhs.zooAnimal.end(); ++it){
            zooAnimal.push_back((*it)->clone());
        }
    }

    void addAnimal(Animal *a){
        zooAnimal.push_back(a);
    }

    void showAllAnimals(){
       for (list<Animal*>::const_iterator it = zooAnimal.begin(); it != zooAnimal.end(); ++it){
            (*it)->yell();
        } 
    }

private:
    list<Animal*> zooAnimal;

};

int Cat::num = 0;
int Dog::num = 0;

inline void print(Animal &m){
    m.yell();
}

int main(){
    Animal *p[2];
    Zoo z1;
    z1.addAnimal(new Cat("Cindy",5));
    z1.addAnimal(new Dog("Mike",10));

    // for (int i = 0; i < 2; ++i){
    //     print((*p[i]));
    //     cout << typeid(*p[i]).name() << endl;
    // }
    Zoo z2(z1);
    
    z2.addAnimal(new Cat("Daisy",3));
    z2.addAnimal(new Dog("Bob",5));
    z2.addAnimal(new Cat("Linda",8));

    z2.showAllAnimals();
    


    return 0;
}



