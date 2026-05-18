# Visitor Pattern

### Пример с геометрични фигури

#### Проблем
Имаме фунцкия canInsert(Shape& shape) и искаме да знаем дали може да впишем една фигура в друга. Какви варианти имаме?
 - да проверим от какъв тип е *shape* и след това да имлементираме функция за този тип фигура. -> Решение е, но е много бавно и изисква много ресурси
 - да dynamic_cast-ваме според фигурата -“ -> Решение е, но е много бавно и изисква много ресурси

#### Решение
Имаме интерфейс **Shape**. Ще използваме функцията *canFirInto(const Shape& outer)* като имаме и помощните функции, с които да проверим вече ясната фигура (в тях е истинската логика)
```c++
class Shape {
public:
    virtual bool canFitInto(const Shape& outer) const = 0;

    virtual bool fitIntoCircle(const Circle&) const = 0;
    virtual bool fitIntoRectangle(const Rectangle&) const = 0;
    virtual bool fitIntoTriangle(const Triangle&) const = 0;
    virtual ~Shape() = default;
};
```
```c++
class Circle : public Shape {
private:
    double r;
public:
    bool canFitInto(const Shape& outer) const override {
        return outer.fitIntoCircle(*this);
    }

    bool fitIntoCircle(const Circle& c) const override {
        return r <= c.r;
    }

    bool fitIntoRectangle(const Rectangle& r) const override {
        return 2 * this->r <= min(r.w, r.h);
    }

    bool fitIntoTriangle(const Triangle&) const override {
        return false;
    }
};
```
```c++
class Rectangle : public Shape {
private:
    double w, h;
public:
    bool canFitInto(const Shape& outer) const override {
        return outer.fitIntoRectangle(*this);
    }

    bool fitIntoCircle(const Circle&) const override {
        return false; // simplified rule
    }

    bool fitIntoRectangle(const Rectangle& r) const override {
        return w <= r.w && h <= r.h;
    }

    bool fitIntoTriangle(const Triangle&) const override {
        return false;
    }
};
```
```c++
class Triangle : public Shape {
private:
    double b, h;
public:
    bool canFitInto(const Shape& outer) const override {
        return outer.fitIntoTriangle(*this);
    }

    bool fitIntoCircle(const Circle&) const override {
        return false;
    }

    bool fitIntoRectangle(const Rectangle& r) const override {
        return b <= r.w && h <= r.h;
    }

    bool fitIntoTriangle(const Triangle&) const override {
        return b <= outerBase && h <= outerHeight; // simplified assumption
    }
};
```
И имаме тази помощна функция
```c++
bool canInsertInto(const Shape& inner, const Shape& outer) {
    return inner.canFitInto(outer);
}
```


## Използване
```c++
canInsertInto(cirle, rectangle); // може ли circle да се впише в rectangle
```
1. Влизаме в помошната функция => (circle.canFirInto(rectangle))
1. Извикваме rectangle.fitIntoCircle(circle) 