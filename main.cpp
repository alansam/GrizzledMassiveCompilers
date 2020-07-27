
#include <iostream>

//using namespace std;

#define MAXARRAY 5

class myarray;
void fill(myarray & a2, myarray & a3, myarray & a4);
void filled(myarray const & a1, myarray const & a2,
            myarray const & a3, myarray const & a4);
void report(myarray const & a1, myarray const & a2,
            myarray const & a3, myarray const & a4);

// --------------------------------------------------------------
class myarray {
private:
  int value[MAXARRAY];

public:
  // ------------------------------------------------------------
  myarray() = default;
  myarray(myarray const & that) = default;
  myarray(myarray && that) = default;
  ~myarray() = default;

  // ------------------------------------------------------------
  void setvalue(int index, int newvalue) {
    value[index] = newvalue;
  }

  // ------------------------------------------------------------
  int getvalue(int index) const {
    return value[index];
  }

  // ------------------------------------------------------------
  // pass by reference so that a copy isn't made
  // use "const" so that it isn't modified
  myarray & operator =(myarray const & array2) {
    // Can check if both sides are equal,
    if (this != &array2) {
      for (int i = 0; i < MAXARRAY; i++) {
        value[i]=array2.value[i];
      }
    }

    return *this;
  }

  myarray & operator =(myarray && array2)  = default;
};

int main () {
  myarray array2, array3, array4;
  // ------------------------------------------------------------
  myarray array1a;

  //INITIALIZE & PRINT
  std::cout << "\na --------------------------------------"
            << std::endl;
  fill(array2, array3, array4);
  filled(array1a, array2, array3, array4);

  //ASSIGN
  (array1a = array2 = array3) = array4;
  //array3 and array1 now equal array2
  //PRINT
  std::cout << "\n(array1 = array2 = array3) = array4;" << std::endl;
  report(array1a, array2, array3, array4);

  // ------------------------------------------------------------
  myarray array1b;

  //INITIALIZE & PRINT
  std::cout << "\nb --------------------------------------"
            << std::endl;
  fill(array2, array3, array4);
  filled(array1b, array2, array3, array4);

  //ASSIGN
  array1b = (array2 = array3) = array4;
  //PRINT
  std::cout << "\narray1 = (array2 = array3) = array4;" << std::endl;
  report(array1b, array2, array3, array4);

  // ------------------------------------------------------------
  myarray array1c;

  //INITIALIZE & PRINT
  std::cout << "\nc --------------------------------------"
            << std::endl;
  fill(array2, array3, array4);
  filled(array1c, array2, array3, array4);

  //ASSIGN
  array1c = array2 = array3 = array4;
  //PRINT
  std::cout << "\narray1 = array2 = array3 = array4;" << std::endl;
  report(array1c, array2, array3, array4);

  // ------------------------------------------------------------
  myarray array1d;

  //INITIALIZE & PRINT
  std::cout << "\nd --------------------------------------"
            << std::endl;
  fill(array2, array3, array4);
  filled(array1d, array2, array3, array4);

  //ASSIGN
  array1d = array3 = (array2 = array4);
  //PRINT
  std::cout << "\narray1 = array3 = (array2 = array4);" << std::endl;
  report(array1d, array2, array3, array4);

  // ------------------------------------------------------------
  myarray array1e;

  //INITIALIZE & PRINT
  std::cout << "\ne --------------------------------------"
            << std::endl;
  fill(array2, array3, array4);
  filled(array1e, array2, array3, array4);

  //ASSIGN
  array1e = (array3 = array2 = array4);
  //PRINT
  std::cout << "\narray1 = (array3 = array2 = array4);" << std::endl;
  report(array1e, array2, array3, array4);

  // ------------------------------------------------------------
  myarray array1f;

  //INITIALIZE & PRINT
  std::cout << "\nf --------------------------------------"
            << std::endl;
  fill(array2, array3, array4);
  filled(array1f, array2, array3, array4);

  //ASSIGN
  array1f = (array3 = array2) = array4;
  //PRINT
  std::cout << "\narray1 = (array3 = array2) = array4;" << std::endl;
  report(array1f, array2, array3, array4);

  return 0;
}

// --------------------------------------------------------------
void fill(myarray & array2, myarray & array3, myarray & array4) {
  for (int i = 0; i < MAXARRAY; i++)
  {
    array2.setvalue(i, i);
    array3.setvalue(i, i + 1);
    array4.setvalue(i, i + 2);
  }

  return;
}

// --------------------------------------------------------------
void filled(myarray const & array1, myarray const & array2,
            myarray const & array3, myarray const & array4) {
  std::cout << "array1   array2   array3   array4" << std::endl;
  for (size_t i = 0; i < MAXARRAY; i++) {
    std::cout << /*array1.getvalue(i)*/ "~"  << "        "
              << array2.getvalue(i) << "        "
              << array3.getvalue(i) << "        "
              << array4.getvalue(i)
              << std::endl;
  }

  return;
}

// --------------------------------------------------------------
void report(myarray const & array1, myarray const & array2,
            myarray const & array3, myarray const & array4) {

  //PRINT
  std::cout << "array1   array2   array3   array4" << std::endl;
  for (size_t i = 0; i < MAXARRAY; i++) {
    std::cout << array1.getvalue(i) << "        "
              << array2.getvalue(i) << "        "
              << array3.getvalue(i) << "        "
              << array4.getvalue(i)
              << std::endl;
  }
  std::cout << std::endl;
  std::cout << "address of the arrays:" << std::endl;
  std::cout << "array1   array2   array3   array4" << std::endl;
  std::cout << &array1 << "  "
            << &array2 << "  "
            << &array3 << "  "
            << &array4
            << std::endl;

  return;
}

//why array1 isnt equal to array4 ?
