#include "buffer.h"

// Some Abstract Data Type
//
class ADT {
public:
    ADT() = default;
    ADT(const ADT& ) = default;// delete;
    ADT& operator =(const ADT& ) = default;// delete;
    ADT(int init){}

    void op_A() const;
    void op_B();
    void op_C();

private:
    // Attributes...
};


int main()
{
    Buffer<ADT, 16> adt_buffer { };   // Should be fine...?
}

// int main()
// {
//     Buffer<int, 16>   int_buf { };
//     Buffer<double, 8> dbl_buf { };

//     int_buf.push(100);

//     // etc...
// }
