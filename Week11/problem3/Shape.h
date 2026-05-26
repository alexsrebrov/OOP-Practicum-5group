#pragma once
#include<string>
class Shape {
protected:
std::string color;
public:
    Shape(const std::string& color);
  const  std::string& getColour() const;

};