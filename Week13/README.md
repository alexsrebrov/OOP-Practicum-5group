# Ламбди

**Ламбите** са малки функции, които нямат име и могат да бъдат написани директно на място, където очакване да бъде подаден параметър функция. Често намират употреба при кратки функции.

### Синтаксис

```c++
[capture] (parameters) { code };
```

Пример:
```c++
#include <iostream>
#include <functional> // За да може да използваме function<>

void myFunc(function<void(string)> func) { func("Alex!"); }

int main() {
    string output = "Hello, ";
    string name = "Mitko!";

    function<void(string)> message1 = [output](string name) {
        cout << output << name << '\n';
    };

    auto message2 = [output](string name) {
        cout << output << name << '\n';
    };
    
    void (*message3)(string, string) =
        [](string output, string name) {
            cout << output << name << '\n';
        }; // Cannot have capture

    message1(name);             // Hello, Mitko!
    message2(name);             // Hello, Mitko!
    message3(output, name);     // Hello, Mitko!
    myFunc(message1);           // Hello, Alex!
    myFunc(([output](string name) 
    { cout << output << name << '\n'; })); // Hello, Alex!

    return 0;
}
```

#### Как работи capture?
Има три начина по, които може да capture-нем:
 - По референция
 - По стойност
 - И по двете

```c++
// capture by reference
int main() {
    vector<int> vec = {10, 20, 30, 40, 50};

    auto lambda = [&vec]() {
        for (int& num : vec) {
            num *= 10;
        }
    };
    lambda();

    for (int num : vec) {
        cout << num << " ";
    } // Output [ 100, 200, 300, 400, 500 ]

    return 0;
}
```

```c++
// capture by value
int main() {
    vector<int> vec = {10, 20, 30, 40, 50};

    auto lambda = [vec]() {
        for (int num : vec) { // Cannot get int& num, because is const int
            cout << (num *= 10) << " ";
        }
    };
    lambda();  // Output [ 100, 200, 300, 400, 500 ]

    for (int num : vec) {
        cout << num << " ";
    } // Output [ 10, 20, 30, 40, 50 ]

    return 0;
}
```

```c++
int main() {
    vector<int> vec1 = {10, 20, 30, 40, 50};
    vector<int> vec2 = {1, 2, 3, 4, 5};

    auto lambda = [&vec1, vec2]() {
        for (int& num : vec1) {
            num *= 10;
        }
        for (int num : vec2) {
            cout << num * 10 << " ";
        }
        cout << endl;
    };

    lambda(); // Output [ 10, 20, 30, 40, 50 ]

    cout << "Vector 1: ";
    for (int num : vec1) cout << num << " "; // Output [ 100, 200, 300, 400, 500 ]

    cout << "\nVector 2: ";
    for (int num : vec2) cout << num << " "; // Output [ 1, 2, 3, 4, 5 ]

    return 0;
}
```

# Изключения