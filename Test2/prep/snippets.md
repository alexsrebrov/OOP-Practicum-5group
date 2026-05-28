# Теоретични въпроси

## Задача 1
```c++
struct A {
    char c;
    int num;

    A(int num, char c) : num(num), c(c) { 
        cout << "Constructor=" << num << "," << c << '\n';
    }

    ~A() { 
        cout << "Destructor=" << num << "," << c << '\n';
    }
};

int main() {
    vector<unique_ptr<A>> v;
    v.push_back(make_unique<A>(1, 'a'));
    v.push_back(make_unique<A>(2, 'b'));
    v.push_back(make_unique<A>(3, 'c'));

    erase_if(v, [](const auto& p) {
        return p->num % 2 == 1;
    });

    cout << v.size() << '\n';
    
    sort(v.begin(), v.end(),
        [](const auto& a, const auto& b) { 
            return a->c > b->c; 
        });

    for (auto& p : v) {
        cout << p->num << "," << p->c << "\n";
    }
}
```

## Задача 2
```c++
#include <iostream>
#include <stdexcept>
using namespace std;

struct Resource {
    string name;
    Resource(const string& n) : name(n) {
        cout << "Class: " << name << "\n";
    }
    ~Resource() {
        cout << "~" << name << "\n";
    }
};

void inner() {
    Resource r3("C");
    throw runtime_error("Error caught\n");
    Resource r4("D");
}

void middle() {
    Resource r2("B");
    inner();
}

void outer() {
    Resource r1("A");
    try {
        middle();
    }
    catch (const runtime_error& e) {
        cout << "caught: " << e.what();
    }
}

int main() {
    outer();
}
```

## Задача 3
```c++
struct Base : runtime_error {
    Base(const string& str) : runtime_error(str) {}
};

struct Der : Base {
    Der(const string& str) : Base(str) {}
};

struct A {
    A() {throw Der("error");}
    A(int a) {throw Base("error");}
};

int main() {
    try {
        A a;
    } catch (const runtime_error& e) {
        cout << "Caught runtime_error exception: " << e.what() << endl;
    } catch (const Base& e) {
        cout << "Caught Base exception: " << e.what() << endl;
    } catch (const Der& e) {
        cout << "Caught Der exception: " << e.what() << endl;
    }

    try {
        A a(5);
    } catch (const Der& e) {
        cout << "Caught Der exception: " << e.what() << endl;
    } catch (const Base& e) {
        cout << "Caught Base exception: " << e.what() << endl;
    } catch (const runtime_error& e) {
        cout << "Caught runtime_error exception: " << e.what() << endl;
    }
}
```

## Задача 4
```c++
struct A {
    int num;
    A(int n) : num(n) { cout << "A(" << num << ")\n"; }
    A(const A &o) : num(o.num) { cout << "CA(" << num << ")\n"; }
    virtual ~A() { cout << "~A(" << num << ")\n"; }
};

struct B : A {
    char c;
    B(int n, char ch) : A(n), c(ch) { cout << "B(" << c << ")\n"; }
    B(const B &o) : A(o), c(o.c) { cout << "CB(" << c << ")\n"; }
    ~B() override { cout << "~B(" << c << ")\n"; }
};

struct C : A {
    double d;
    C(int n, double val) : A(n), d(val) { cout << "C(" << d << ")\n"; }
};

void func(A a) {
    cout << "func: " << a.num << "\n";
}

int main() {
    vector<shared_ptr<A>> vec;
    vec.push_back(make_shared<B>(1, 'x'));
    vec.push_back(make_shared<C>(2, 3.14));
    vec.push_back(vec[0]);

    unique_ptr<A> ptr1 = make_unique<B>(3, 'y');
    unique_ptr<A> ptr2 = make_unique<C>(4, 2.71);
    func(*ptr1);
    func(*ptr2);
}
```

## Задача 5
```c++
struct A {
    virtual void a() const { cout << "A::a\n"; }
    virtual void b() const { cout << "A::b\n"; }
    virtual void c() const = 0;
};

struct B : A {
    void a() const override { cout << "B::a\n"; }
    void c() const override { cout << "B::c\n"; }
};

struct C : A {
    void b() const override { cout << "C::b\n"; }
};

int main() {
    A* a = new B();
    A* b = new C();

    a->a();
    a->b();
    a->c();

    b->a();
    b->b();
    b->c();
}
```

## Задача 6
```c++
template<typename T>
struct Label {
    static void print() { cout << "unknown\n"; }
};

template<>
struct Label<int> {
    static void print() { cout << "int\n"; }
};

template<>
struct Label<double> {
    static void print() { cout << "double\n"; }
};

int main() {
    Label<int>::print();
    Label<double>::print();
    Label<char>::print();
    Label<float>::print();
}
```

---


#### Задача 1
```
Constructor=1,a
Constructor=2,b
Constructor=3,c
Destructor=1,a
Destructor=3,c
1
2,b
```
#### Задача 2
```
Class: A
Class: B
Class: C
~C
~B
caught: Error caught
~A
```
#### Задача 3
```
Caught runtime_error exception: error
Caught Base exception: error
```
#### Задача 4
```
A(1)
B(x)
A(2)
C(3.14)
A(3)
B(y)
A(4)
C(2.71)
CA(3)
func: 3
~A(3)
CA(4)
func: 4
~A(4)
~A(4)
~B(y)
~A(3)
~A(2)
~B(x)
~A(1)
```
#### Задача 5
```
компилационна грешка (C трябва да override-не c())
Ако това се оправи:
B::a
A::b
B::c
A::a
C::b
C::c
```
### Задача 6
```
int
double
unknown
unknown
```
