//defining a comparison operator
//refer CS32 Lec 9 slide 16

//operator> and const are tricky parts

//1) Generic Comparisons

bool operator>(const Dog &a, const Dog &b){
  if (a.weight > b.weight)
    return true;
  else
    return false;
}

//2) Generic Functions

//3) Generic Classes
