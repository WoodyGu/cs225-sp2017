#ifndef _SQUARE_H
#define _SQUARE_H
/*We need to overload operator because by default,C++ implements bitwise copying or"=". So if we allow the default '=', the pointer will be pointing
to the same memory address, which is a shallow copy. If we delete the dynamic memory, that part of the copied object will also disappear.
*/
class Square {
    private:
        string name;
        double * lengthptr;
    public:
        Square();
        Square(const Square & old);
        ~Square();
        void setName(string newName);
        void setLength(double newVal);
        string getName() const;
        double getLength() const;
	Square operator=(const Square& other);
	Square operator+(const Square& a);
};

#endif
