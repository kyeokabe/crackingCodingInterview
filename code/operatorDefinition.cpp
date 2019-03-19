//defining a comparison operator
//refer CS32 Lec 9 slide 16

//operator> and const are tricky parts

bool operator>(const Dog &a, const Dog &b){
  if (a.weight > b.weight)
    return true;
  else
    return false;
}
